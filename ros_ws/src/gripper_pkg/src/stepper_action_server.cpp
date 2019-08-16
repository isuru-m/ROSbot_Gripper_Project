#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <gripper_pkg/stepActionAction.h>

/*
class MoveZaxis
{
protected:
	ros::NodeHandle nh_;
	actionlib::SimpleActionServer<gripper_pkg::stepActionAction> step_as;
	std::string action_name_;
	
	//create messages that are used to publish the feedback and results
	gripper_pkg::stepActionFeedback fb_;
	gripper_pkg::stepActionResults result_;
	
public:
	

}
*/


int main(int argc, char **argv)
{
	ros::init(argc, argv, "stepper_action_server");
	ros::NodeHandle n;


}
