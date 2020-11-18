#include "ros/ros.h"
#include "lab2_service/Typification.h"

bool type(lab2_service::Typification::Request &req, lab2_service::Typification::Response &res)
{
 int num = req.lenght;

 if (625 < num && num <= 740) {
    res.color = "color is red";
 } else if (590 < num && num <= 625) {
    res.color = "color is orange";
 } else if (565 < num && num <= 590) {
    res.color = "color is yellow";
 } else if (500 < num && num <= 565) {
    res.color = "color is green";
 } else if (485 < num && num <= 500) {
    res.color = "color is cyan";
 } else if (440 < num && num <= 485) {
    res.color = "color is blue";
 } else if (380 <= num && num <= 440) {
    res.color = "color is violet";
 } else {
    res.color = "not in the visible light spectrum";
 }

 ROS_INFO_STREAM(res.color);
 return true;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "color_from_lenght");
 ros::NodeHandle n;

 ros::ServiceServer servive = n.advertiseService("enter_lenght", type);
 ROS_INFO("Ready to enter the lenght.");
 ros::spin();

 return 0;
}
