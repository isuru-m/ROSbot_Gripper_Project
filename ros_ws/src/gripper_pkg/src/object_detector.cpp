#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <opencv2/opencv.hpp>

#define BRACKET 32
#define CASTER 31

int id = 0;
ros::Publisher action_pub;
geometry_msgs::Twist set_vel;
int camera_center = 320; // left 0, right 640

void objectCallback(const std_msgs::Float32MultiArrayPtr &object)
{
   if (object->data.size() > 0)
   {
      id = object->data[0];

      float objectWidth = object->data[1];
      float objectHeight = object->data[2];
      float x_pos;
      float y_pos;
      //float speed_coefficient = (float)camera_center / max_ang_vel / 4;

      // Find corners OpenCV
      cv::Mat cvHomography(3, 3, CV_32F);
      std::vector<cv::Point2f> inPts, outPts;
      switch (id)
      {
      case BRACKET:
      	 ROS_INFO("Bracket detected");
         cvHomography.at<float>(0, 0) = object->data[3];
         cvHomography.at<float>(1, 0) = object->data[4];
         cvHomography.at<float>(2, 0) = object->data[5];
         cvHomography.at<float>(0, 1) = object->data[6];
         cvHomography.at<float>(1, 1) = object->data[7];
         cvHomography.at<float>(2, 1) = object->data[8];
         cvHomography.at<float>(0, 2) = object->data[9];
         cvHomography.at<float>(1, 2) = object->data[10];
         cvHomography.at<float>(2, 2) = object->data[11];

         inPts.push_back(cv::Point2f(0, 0));
         inPts.push_back(cv::Point2f(objectWidth, 0));
         inPts.push_back(cv::Point2f(0, objectHeight));
         inPts.push_back(cv::Point2f(objectWidth, objectHeight));
         cv::perspectiveTransform(inPts, outPts, cvHomography);

         x_pos = (int)(outPts.at(0).x + outPts.at(1).x + outPts.at(2).x +
                       outPts.at(3).x) /
                 4;

        y_pos = (int)(outPts.at(0).y + outPts.at(1).y + outPts.at(2).y +
                       outPts.at(3).y) /
                 4;
         break;
         
      case CASTER:
      	 ROS_INFO("Caster wheel detected");
         cvHomography.at<float>(0, 0) = object->data[3];
         cvHomography.at<float>(1, 0) = object->data[4];
         cvHomography.at<float>(2, 0) = object->data[5];
         cvHomography.at<float>(0, 1) = object->data[6];
         cvHomography.at<float>(1, 1) = object->data[7];
         cvHomography.at<float>(2, 1) = object->data[8];
         cvHomography.at<float>(0, 2) = object->data[9];
         cvHomography.at<float>(1, 2) = object->data[10];
         cvHomography.at<float>(2, 2) = object->data[11];

         inPts.push_back(cv::Point2f(0, 0));
         inPts.push_back(cv::Point2f(objectWidth, 0));
         inPts.push_back(cv::Point2f(0, objectHeight));
         inPts.push_back(cv::Point2f(objectWidth, objectHeight));
         cv::perspectiveTransform(inPts, outPts, cvHomography);

         x_pos = (int)(outPts.at(0).x + outPts.at(1).x + outPts.at(2).x +
                       outPts.at(3).x) /
                 4;
 

         y_pos = (int)(outPts.at(0).y + outPts.at(1).y + outPts.at(2).y +
                       outPts.at(3).y) /
                 4;
         ROS_INFO("x pos: [%f] and y pos: [%f]", x_pos, y_pos);
         break;
         
      default: // other object
         set_vel.linear.x = 0;
         set_vel.angular.z = 0;
      }
      action_pub.publish(set_vel);
   }
   else
   {
      // No object detected
      set_vel.linear.x = 0;
      set_vel.angular.z = 0;
      action_pub.publish(set_vel);
      ROS_INFO("No object detected");
   }
}

int main(int argc, char **argv)
{
   std_msgs::String s;
   std::string str;
   str.clear();
   str.append("");
   std::to_string(3);
   s.data = str;
   ros::init(argc, argv, "object_detector");
   ros::NodeHandle n("~");
   ros::Subscriber sub = n.subscribe("/objects", 1, objectCallback);
   ros::Rate loop_rate(50);
   action_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
   set_vel.linear.x = 0;
   set_vel.linear.y = 0;
   set_vel.linear.z = 0;
   set_vel.angular.x = 0;
   set_vel.angular.y = 0;
   set_vel.angular.z = 0;
   while (ros::ok())
   {
      ros::spinOnce();
      loop_rate.sleep();
   }
}
