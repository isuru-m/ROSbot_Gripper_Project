#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf/transform_broadcaster.h>

tf::Transform transform;
tf::Quaternion q;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  float pi=3.1415;
  float piDiv4=pi/4;
  float piDiv6=pi/6;
  
  // define the quaternion from euler angles
  q = tf::createQuaternionFromRPY(0, 0, -piDiv4);
  transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
  transform.setRotation(q);
  
  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = 0.170;
  goal.target_pose.pose.position.y = -0.120;

  ROS_INFO_STREAM(q[0]);
  ROS_INFO_STREAM(q[1]);
  ROS_INFO_STREAM(q[2]);
  ROS_INFO_STREAM(q[3]);   
  
  goal.target_pose.pose.orientation.z = q[2];
  goal.target_pose.pose.orientation.w = q[3];
  //goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward");
  else
    ROS_INFO("The base failed to move forward 1 meter for some reason");

  return 0;
}
