#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Vector3.h>

void rpy_callback(const geometry_msgs::Vector3ConstPtr &rpy)
{
	float yaw = rpy->z;
	ROS_INFO("yaw value: [%f]", yaw);
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "custom_move_base");
   ros::NodeHandle n("~");
   ros::Subscriber pose_sub = n.subscribe("/rpy", 1, rpy_callback);
   ros::Rate loop_rate(100);
   while (ros::ok())
   {
      ros::spinOnce();
      loop_rate.sleep();
   }
}


