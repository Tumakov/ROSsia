#include "ros/ros.h"
#include "std_msgs/Bool.h"
using namespace std;

static ros::Publisher g_publisher_bool;

void getMessageCallback(const std_msgs::Bool::ConstPtr& msg)
{
  bool received_bool_value = msg->data;
  
  static bool count = false;
  static bool first_msg;

  if (!count)
  {
    first_msg = received_bool_value;
    count = true;
  }  
  else
  {
    std_msgs::Bool response;
    response.data = (first_msg && received_bool_value) || !first_msg;
    first_msg = false;
    count = false;

    g_publisher_bool.publish(response);
  }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lab_one");
    ros::NodeHandle n;

    //init publisher
    const int PUBLISHER_MESSAGE_QUEUE_SIZE = 2;
    const std::string PUBLISHER_TOPIC_NAME = "bool_out";
    g_publisher_bool = n.advertise<std_msgs::Bool>(PUBLISHER_TOPIC_NAME, PUBLISHER_MESSAGE_QUEUE_SIZE);

    //init subscriber
    const int SUBSCRIBER_MESSAGE_QUEUE_SIZE = 2;
    const std::string SUBSCRIBER_TOPIC_NAME = "bool_in";
    ros::Subscriber subscriber = n.subscribe(SUBSCRIBER_TOPIC_NAME, SUBSCRIBER_MESSAGE_QUEUE_SIZE, getMessageCallback);

    ROS_INFO("node lab_one is ready");
    ros::spin();

    return 0;
}
