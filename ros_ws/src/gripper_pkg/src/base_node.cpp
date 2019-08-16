#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/Vector3.h>

// Header files for the services used
#include <gripper_pkg/stepService.h>
#include <gripper_pkg/servoService.h>

// Header fiiles for the actions used
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <gripper_pkg/stepActionAction.h> // Action is appended 



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
	
	ros::Subscriber frontr_sub = n.subscribe("range/fr", 1, rangefrCallback);
	ros::Subscriber end_stop = n.subscribe("end_stop", 1, endStopCallback); 
	ros::Subscriber us_timer_sub = n.subscribe("us_timer", 1, timerCallback);
	
	ros::ServiceClient stepClient = n.serviceClient<gripper_pkg::stepService>("goTo_step");
	ros::service::waitForService("goTo_step");
	gripper_pkg::stepService step_srv;
	//gripper_pkg::stepService::Response res;
	
	ros::ServiceClient gripClient = n.serviceClient<gripper_pkg::servoService>("goTo_grip");
	ros::service::waitForService("goTo_grip");	
	gripper_pkg::servoService grip_srv;
	//gripper_pkg::servoService::Response res;
				
	
	grip_srv.request.radius = 40.0;
	gripClient.call(grip_srv);
	ros::Duration(1).sleep();
	
	step_srv.request.distance = 15;
	step_srv.request.direction = false; // false- move downwards, true- upwards
	step_srv.request.initialise = false; //  true value for this should ignore the direction request
	stepClient.call(step_srv);
	ros::Duration(1).sleep();
	
	grip_srv.request.radius = 0.0;
	gripClient.call(grip_srv);
	ros::Duration(1).sleep();
	
	//ROS_INFO("Service reply: [%d]", success);
	
	
	
	//servo_pub = n.advertise<geometry_msgs::Vector3>("/servo_gripper", 10); 
	
	
	while(ros::ok())
	{
		if (step_srv.response.success)
		{
			ROS_INFO("Stepper motion finished");
		}	
		else if (!step_srv.response.success)
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
