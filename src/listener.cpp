#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]",msg->data.c_str());
}
//callback function will called when a new message has arrived on the chatter topic
//used a boost shared_ptr

int main(int argc,char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);//Subscribe to the required topic, i.e., here - chatter
    ros::spin();//loop that calls the message in Callback fn.
    //will exit when ros::ok() returns False

    return 0;
}

//Init ROS
//Subscribe to chatter topic
//Spin, waiting for msg to arrive
//When msg arrives, 'chatterCallback()' fn. is called
