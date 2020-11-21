#include "ros/ros.h"
#include "lab2/Typification.h"
#include <ctime>

int main(int argc, char **argv)
{
 ros::init(argc, argv, "color_from_lenght_client");
 ros::NodeHandle n;

 const std::string SERVICE_NAME = "lab2";
 ros::ServiceClient client = n.serviceClient<lab2::Typification>(SERVICE_NAME);

 ros::Rate loop_rate(1);
 std::srand(time(0));
  
 ROS_INFO("client is ready");

 while(ros::ok())
 {
   lab2::Typification serviceRequest;

   serviceRequest.request.lenght = ((double)std::rand()) / RAND_MAX * 1000;

   if (client.call(serviceRequest))
   {
     ROS_INFO("Service awnsers.\nlenght is %d\ncolor is %s\n",
     serviceRequest.request.lenght, 
     serviceRequest.response.response
     );
   }
   else
   {
     ROS_ERROR("Failed to call service");
     return 1;
   }
  	
   ros::spinOnce();
   loop_rate.sleep();
 }

 return 0;
}
