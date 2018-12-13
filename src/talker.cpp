#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc,char **argv)
{
    ros::init(argc,argv,"talker"); //initializing ros 
    ros::NodeHandle n; //creating a handle for this process node
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000); 
    //publishing a msg of type String which tells master that node is listening on 'chatter' with 1000 max msgs
    //advertise serves - publish method and - unadvertise automatically if it goes out of scope
    ros::Rate loop_rate(10); //loop freq.

    int count = 0;
    while (ros::ok())
    //returns False when - CTrL+C is pressed or
    // - kicked out of the network
    // - ros::shutdown() is called by another application
    // - all ros NodeHandles have been destroyed
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"Hello World"<<count;
        msg.data = ss.str();

        ROS_INFO("%s",msg.data.c_str());

        chatter_pub.publish(msg); // msg is being broadcast
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}

//Init. ROS
//Advertise the published msg
//Loop while publishing msg to loop time, i.e., here - 10

