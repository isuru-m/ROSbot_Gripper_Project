#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/Vector3.h>
#include <std_srvs/Empty.h>

#include <gripper_pkg/servoService.h>


ros::Publisher servo_pub;
geometry_msgs::Vector3 servo_msg;

double rad2pwidth(double rad)
{
	double pw = -25*rad + 2500;
	return pw;
}


bool gripperCallback(gripper_pkg::servoService::Request& req, gripper_pkg::servoService::Response& res)
{
	float radius = req.radius;	
	ROS_INFO("Radius recieved: [%f]", radius);
	float pulse_width = rad2pwidth(radius);
	ROS_INFO("Pulse Width: [%f]", pulse_width);
	servo_msg.y = pulse_width;
	servo_pub.publish(servo_msg);		 
	res.success = true;	
		
	return true;
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "servo_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(50);   
	
	servo_pub = n.advertise<geometry_msgs::Vector3>("servo_gripper", 10);
	
	while(servo_pub.getNumSubscribers() == 0)
	{	
		loop_rate.sleep();
		ROS_INFO("Servo node waiting for subscribers");
	}
		
	servo_msg.x = 20000; // set 20ms period(or 20,000us)

	
	ros::ServiceServer server = n.advertiseService("goTo_grip", gripperCallback);
	ROS_INFO("Servo server registered");
	
	while(ros::ok)
	{
	ros::spinOnce();
	loop_rate.sleep();
	}

}
