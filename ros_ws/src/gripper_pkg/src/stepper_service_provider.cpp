#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/Vector3.h>
#include <std_srvs/Empty.h>

#include <gripper_pkg/stepService.h>


ros::Publisher stepper_pub;
geometry_msgs::Vector3 stepper_msg;

ros::Publisher enable_step_pub;
std_msgs::Bool enable_step_msg;

ros::Publisher dir_pub;
std_msgs::Bool step_dir_msg;

float total_distance = 0.0;
bool limit = true; 

void endStopCallback(const std_msgs::Bool::ConstPtr& msg)
{
	// end stop switch is set to operate in Normally Open (NO) configureation 
	bool limit = msg->data;
	ROS_INFO("Limit value (callback): [%s]", limit ? "Released" : "Pressed");
		
}

double dist2time(double dist)
{
	int freq = 400; // 400Hz or 2500 us
	double K_g = 400.0; 
	double stepper_time = 0.0; 
	
	return stepper_time = K_g*dist/freq;		
}

bool stepperCallback(gripper_pkg::stepService::Request& req, gripper_pkg::stepService::Response& res)
{
	
	stepper_msg.x = 2500;
	stepper_msg.y = 1250;
	stepper_pub.publish(stepper_msg); // set the pulse width
	
	step_dir_msg.data = req.direction; // false- move downwards, true- upwards
	dir_pub.publish(step_dir_msg);
	
	if (req.initialise)
	{
		/* Do Nothing 
		step_dir_msg.data = true; // false- move downwards, true- upwards
		dir_pub.publish(step_dir_msg);
		
		while(limit)
		{
			ROS_INFO("Limit value: [%s]", limit ? "Released" : "Pressed");
			enable_step_msg.data = false; // turn the motor on
			enable_step_pub.publish(enable_step_msg);
			ROS_INFO("Initialising Z axis");
			ros::Duration(0.05).sleep();
			
		}
		enable_step_msg.data = true; // turn the motor off
		enable_step_pub.publish(enable_step_msg);
		ROS_INFO("End stop reached");
		*/
	}
	
	if (!req.initialise)
	{
		double distance = req.distance;
		ROS_INFO("Distance recieved %f", distance);
	
		double stepper_time = dist2time(distance);  // Calculate time to move a given distance
		//ROS_INFO("Step Duration: [%f]", stepper_time);
	
		// Time and duration calucualtion 
		//ros::Time beginTime = ros::Time::now();
		double beginTime = ros::Time::now().toSec();
		//ROS_INFO("Begin Time: [%f]", beginTime);
		ros::Duration stepDuration = ros::Duration(stepper_time); // temporary fix; z moves 1mm per sec 
		double durationSecs = stepDuration.toSec();
		//ROS_INFO("Step Duration: [%f]", durationSecs);
		//ros::Time endTime = beginTime + stepDuration;
		double endTime = beginTime + durationSecs;
		//ROS_INFO("End Time: [%f]", endTime);
	
		while(ros::Time::now().toSec() < endTime)
		{	
			enable_step_msg.data = false; // turn the motor on
			enable_step_pub.publish(enable_step_msg);
			ROS_INFO("Moving the gripper down");
			ros::Duration(0.25).sleep();
		}
	
		enable_step_msg.data = true; // turn the motor off
		enable_step_pub.publish(enable_step_msg);
		ROS_INFO("Gripper Stopped");
		total_distance += distance; 
	}
	
	res.success = true;	
	
	return true;
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "stepper_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(50);
	
	stepper_pub = n.advertise<geometry_msgs::Vector3>("stepper_height", 10);
	enable_step_pub = n.advertise<std_msgs::Bool>("step_enable", 10);
	dir_pub = n.advertise<std_msgs::Bool>("cmd_dir", 10);
	
	ros::Subscriber end_stop_sub = n.subscribe("end_stop", 1000, endStopCallback); 
		
	while(dir_pub.getNumSubscribers() == 0)
	{	
		loop_rate.sleep();
		ROS_INFO("Stepper node aiting for subscribers");
	}
	
	enable_step_msg.data = true; //turn the motor off
	enable_step_pub.publish(enable_step_msg);
	
	
	
	ros::ServiceServer server = n.advertiseService("goTo_step", stepperCallback);
	ROS_INFO("Stepper server registered");
	
	
	while(ros::ok)
	{
	ros::spinOnce();
	loop_rate.sleep();
	}

}
