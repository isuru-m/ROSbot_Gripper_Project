#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>

tf::Transform transform;
tf::Quaternion q;
float deg2rad = 3.14159/180;

void imu_callback(const geometry_msgs::Vector3 &imu)
{
    static tf::TransformBroadcaster br;
    q = tf::createQuaternionFromRPY(imu.x * deg2rad, imu.y * deg2rad, imu.z * deg2rad);

    transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
    transform.setRotation(q);

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "orientation"));    
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "imu_controller");
    ros::NodeHandle n("~");
    ros::Subscriber pose_sub = n.subscribe("/rpy", 1, imu_callback);

    ros::Rate loop_rate(100);
    while (ros::ok())
    {		
        ros::spinOnce();
        loop_rate.sleep();
    }
}
