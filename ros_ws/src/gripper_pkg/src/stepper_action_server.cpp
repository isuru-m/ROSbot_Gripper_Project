#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/UInt32.h>
#include <geometry_msgs/Vector3.h>
#include <std_srvs/Empty.h>

#include <actionlib/server/simple_action_server.h>
#include <gripper_pkg/stepActionAction.h>


class MoveZaxis
{
protected:
	ros::NodeHandle nh_;
	actionlib::SimpleActionServer<gripper_pkg::stepActionAction> as_;
	std::string action_name_;
	
	//create messages that are used to publish the feedback and results
	gripper_pkg::stepActionFeedback fb_;
	gripper_pkg::stepActionResult result_;
	
	//Subcribers 
	ros::Subscriber end_stop_sub;
	float limit; 
	float total_distance; // used to keep track of distance travelled over pick-place cycles. 
	
	//Pulishers
	ros::Publisher enable_pub;
	ros::Publisher dir_pub;
	ros::Publisher step_pub;
		
public:
	MoveZaxis(std::string name) :
		as_(nh_, name, boost::bind(&MoveZaxis::stepperCallback, this, _1), false), action_name_(name)
		{
			initializeSubscribers();
			initializePublishers();
			as_.start();
		}
	~MoveZaxis(void)
	{
		//deconstructor stuffs 
	}
	
	private:
	
	//initialise subscribers 
	void initializeSubscribers(void)
	{
		end_stop_sub = nh_.subscribe("/end_stop", 10, &MoveZaxis::endStopCallback, this);
		ROS_INFO("Subscriber initialised");
	}
	
	void initializePublishers(void)
	{		
		step_pub = nh_.advertise<geometry_msgs::Vector3>("/stepper_height", 10);
		enable_pub = nh_.advertise<std_msgs::Bool>("/step_enable", 10);
		dir_pub = nh_.advertise<std_msgs::Bool>("/cmd_dir", 10);
		ROS_INFO("Publishers initialised");
	}
	
	void endStopCallback(const std_msgs::Bool::ConstPtr& msg)
	{
		// end stop switch is set to operate in Normally Open (NO) configureation 
		limit = msg->data;
		ROS_INFO("Limit value (callback): [%s]", limit ? "Released" : "Pressed");		
	}
	
	double dist2time(double dist)
	{
		int freq = 625; // 400Hz or 2500 us
		double K_g = 400.0; 
		double stepper_time = 0.0; 
	
		return stepper_time = K_g*dist/freq;		
	}
	
	void stepperCallback(const gripper_pkg::stepActionGoalConstPtr &goal)
	{
		ros::Rate r(50);
		bool success = true;
		
		geometry_msgs::Vector3 step_msg;
		std_msgs::Bool enable_msg;
		std_msgs::Bool dir_msg;
		
		enable_msg.data = true; //turn the motor off
		enable_pub.publish(enable_msg);
		
		step_msg.x = 1600;
		step_msg.y = 800;
		step_pub.publish(step_msg); // set the pulse width
	
		dir_msg.data = goal->direction; // false- move downwards, true- upwards
		dir_pub.publish(dir_msg);
		
		ROS_INFO("The action server %s recieved a distance goal of %f and the feedback is %f ", action_name_.c_str(), goal->distance, fb_.percent_complete);
			
		// Follow this routine if when running for the first time	
		if (goal->initialise)
		{
			
			dir_msg.data = true; // set to true regardless: initilaise is always up
			dir_pub.publish(dir_msg);
		
			while(limit)
			{
				ROS_INFO("Limit value: [%s]", limit ? "Released" : "Pressed");
				enable_msg.data = false; // turn the motor on
				enable_pub.publish(enable_msg);
				ROS_INFO("Initialising Z axis");

				if (as_.isPreemptRequested() || !ros::ok())
				{
					ROS_INFO("%s: Preempted", action_name_.c_str());
					as_.setPreempted();
					success = false;
				}				
				
				ros::Duration(0.05).sleep();
			
			}
			enable_msg.data = true; // turn the motor off
			enable_pub.publish(enable_msg);
			ROS_INFO("End stop reached");
			
		}
		
		// regular operation 
		if (!goal->initialise)
		{
			double distance = goal->distance;
			ROS_INFO("Distance recieved %f", distance);
			
			total_distance = goal->direction ? total_distance += distance : total_distance -= distance;
			distance = (total_distance > 0) ? (distance-total_distance) : distance;
	
			double stepper_time = dist2time(distance);  // Calculate time to move a given distance
	
			// Time and duration calucualtion 
			double beginTime = ros::Time::now().toSec();
			ros::Duration stepDuration = ros::Duration(stepper_time); 
			double durationSecs = stepDuration.toSec();
			double endTime = beginTime + durationSecs;
	
			while(ros::Time::now().toSec() < endTime)
			{	
				enable_msg.data = false; // turn the motor on
				enable_pub.publish(enable_msg);
				ROS_INFO("Moving the gripper down");
				
				fb_.percent_complete = 99;
				//Publish the info in the console 
				as_.publishFeedback(fb_);				

				if (as_.isPreemptRequested() || !ros::ok())
				{
					ROS_INFO("%s: Preempted", action_name_.c_str());
					as_.setPreempted();
					success = false;
				}				
								
				ros::Duration(0.25).sleep();
			}
	
			enable_msg.data = true; // turn the motor off
			enable_pub.publish(enable_msg);
			ROS_INFO("Gripper Stopped");			
			ROS_INFO("Total distance: [%f]", total_distance);
		}
		
		if (success)
		{
			result_.success = true;
			ROS_INFO("%s Action Suceeded", action_name_.c_str());
			as_.setSucceeded(result_);
		}
						
	}

};




int main(int argc, char **argv)
{
	ros::init(argc, argv, "stepper_action_server");
	
	MoveZaxis move("go_to_step");
	ros::Rate rate(1);
	int c = 0;
	
	while(ros::ok())
	{
		ros::spinOnce();
		ROS_INFO("Main loop counter:%d ", c);
		c++;
		rate.sleep();

	}
	


}
