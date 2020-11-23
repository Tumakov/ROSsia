#include "ros/ros.h"
#include "lab2/Typification.h"

int main(int argc, char **argv)
{
 ros::init(argc, argv, "color_from_lenght_server");
 ros::NodeHandle n;

 ros::ServiceServer servive = n.advertiseService("enter_lenght", type);
 ROS_INFO("Ready to enter the lenght.");
 ros::spin();

 return 0;
}
