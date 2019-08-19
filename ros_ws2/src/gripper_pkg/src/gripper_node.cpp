#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/Vector3.h>

#include <gripper_pkg/stepService.h>
#include <gripper_pkg/servoService.h>

/*
ros::Publisher servo_pub;
geometry_msgs::Vector3 servo_msg;
*/

int c = 0;

void rangefrCallback(const sensor_msgs::Range::ConstPtr& range)
{
	//ROS_INFO("Distance = [%f]", range->range);
}

void endStopCallback(const std_msgs::Bool::ConstPtr& msg)
{
	bool limit = true; 
	limit = msg->data;
	if ((limit == false) && (c == 0))
	{
		ROS_INFO("End stop reached");
		c += 1;
	}
	
}

void timerCallback(const std_msgs::UInt32::ConstPtr& msg)
{
	int init_timer = msg->data;
	//ROS_INFO("Timer Value: [%u]", init_timer);
	
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "base_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(50);
	
	ros::Subscriber frontr_sub = n.subscribe("/range/fr", 1, rangefrCallback);
	ros::Subscriber end_stop = n.subscribe("/end_stop", 1, endStopCallback); 
	ros::Subscriber us_timer_sub = n.subscribe("/us_timer", 1, timerCallback);
	
	ros::ServiceClient stepClient = n.serviceClient<gripper_pkg::stepService>("/goTo_step");
	ros::service::waitForService("/goTo_step");
	gripper_pkg::stepService step_srv;
	//gripper_pkg::stepService::Response res;
	
	ros::ServiceClient gripClient = n.serviceClient<gripper_pkg::servoService>("/goTo_grip");
	ros::service::waitForService("/goTo_grip");	
	gripper_pkg::servoService grip_srv;
	//gripper_pkg::servoService::Response res;
	
			
	step_srv.request.distance = 13.5;
	grip_srv.request.radius = 40.0;
	
	
	stepClient.call(step_srv);
	gripClient.call(grip_srv);
	//ROS_INFO("Service reply: [%d]", success);
	
	
	
	//servo_pub = n.advertise<geometry_msgs::Vector3>("/servo_gripper", 10); 
	
	
	while(ros::ok())
	{
		if (step_srv.response.success == 1)
		{
			ROS_INFO("Stepper motion finished");
		}	
		else if (step_srv.response.success == 0)
		{
			ROS_INFO("Stepper motion failed");
		}
		else
		{
			ROS_INFO("No Response from the Server");
		}
		//ros::shutdown();
		ros::spinOnce();
		loop_rate.sleep();
	}

}
