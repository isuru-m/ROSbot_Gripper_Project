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

	ros::ServiceClient gripClient = n.serviceClient<gripper_pkg::servoService>("goTo_grip");
	ros::service::waitForService("goTo_grip");	
	gripper_pkg::servoService grip_srv;
	
	actionlib::SimpleActionClient<gripper_pkg::stepActionAction> ac_("go_to_step", true);
	ROS_INFO("Waiting for action server");
	ac_.waitForServer();
	gripper_pkg::stepActionGoal goal;

				
	// Call the servo service
	grip_srv.request.radius = 40.0;
	gripClient.call(grip_srv);
	ros::Duration(1).sleep();
	
	// Call the stepper action
	goal.distance = 30;
	goal.direction = true; // false- move downwards, true- upwards
	goal.initialise = false; //  true value for this should ignore the direction request
	ac_.sendGoal(goal);
	
	bool finished_b4_timeout = ac_.waitForResult(ros::Duration(60)); // TImeout the action in 60 secs
	ros::Duration(1).sleep();
	
	// Call stepper for a 
	goal.distance = 25;
	goal.direction = false; // false- move downwards, true- upwards
	goal.initialise = false; //  true value for this should ignore the direction request
	ac_.sendGoal(goal);
	
	bool finished_b4_timeout2 = ac_.waitForResult(ros::Duration(60)); // TImeout the action in 60 secs
	ros::Duration(1).sleep();
	
	// Call the servo
	grip_srv.request.radius = 0.0;
	gripClient.call(grip_srv);
	ros::Duration(1).sleep();
	
	if (finished_b4_timeout || finished_b4_timeout2)
	{
		actionlib::SimpleClientGoalState state = ac_.getState();
		ROS_INFO("%s action finished :D ", state.toString().c_str());
	}
	else
	{
		ROS_INFO("Action Time Out :'( ");
	}
	
	return 0;
	
	/*
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
	*/

}
