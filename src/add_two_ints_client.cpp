#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc,char **argv)
{
	ros::init(argc, argv, "add_two_ints_client");
	if (argc != 3)
	{
		ROS_INFO("Usage: add_two_int_client X Y");
		return 1;
	}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
	//Client is Created
	beginner_tutorials::AddTwoInts srv;//Service that was previously made as int64 a||int64 b
 	srv.request.a = atoll(argv[1]);
  	srv.request.b = atoll(argv[2]);
	//atoll - Parses the C-string str interpreting its content as an int
	//Service class with req and res
  	if (client.call(srv))//Calls the service
	//True if service call succeeded else False
  	{
    		ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  	}
  	else
  	{
    		ROS_ERROR("Failed to call service add_two_ints");
    		return 1;
  	}
	return 0;
}
