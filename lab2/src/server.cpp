#include "ros/ros.h"
#include "lab2/Typification.h"

bool type(lab2::Typification::Request &req, lab2::Typification::Response &res)
{
 int num = req.lenght;

 if (625 < num && num <= 740) {
    res.color = "red";
 } else if (590 < num && num <= 625) {
    res.color = "orange";
 } else if (565 < num && num <= 590) {
    res.color = "yellow";
 } else if (500 < num && num <= 565) {
    res.color = "green";
 } else if (485 < num && num <= 500) {
    res.color = "cyan";
 } else if (440 < num && num <= 485) {
    res.color = "blue";
 } else if (380 <= num && num <= 440) {
    res.color = "violet";
 } else {
    res.color = "not in the visible light spectrum";
 }

 ROS_INFO_STREAM(res.color);
 return true;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "color_from_lenght_server");
 ros::NodeHandle n = ros::NodeNandle();

 ros::ServiceServer servive = n.advertiseService("enter_lenght", type);
 ROS_INFO("Ready to enter the lenght.");
 ros::spin();

 return 0;
}
