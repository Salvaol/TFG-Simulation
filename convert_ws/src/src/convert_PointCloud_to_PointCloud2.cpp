#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/point_cloud_conversion.h"

class convert_PointCloud_to_PointCloud2
 {
 public:
 convert_PointCloud_to_PointCloud2()
  {
 //Topic you want to publish
  pub_ = n_.advertise<sensor_msgs::PointCloud2>("/UNEXMIN/laser/scan2", 1000);

//Topic you want to subscribe
  sub_ = n_.subscribe("UNEXMIN/laser/scan", 1000, &convert_PointCloud_to_PointCloud2::callback, this);
 }


void callback(const sensor_msgs::PointCloud::ConstPtr& input)
{
sensor_msgs::PointCloud2 output;


sensor_msgs::convertPointCloudToPointCloud2 (*input,output); 	

pub_.publish(output);
 }


 private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

  };// se termina la clase.

int main(int argc, char **argv)
 {  
  //Initiate ROS
  ros::init(argc, argv, "convert_PointCloud_to_PointCloud2");

  //Create an object of class SubscribeAndPublish that will take care of everything
  convert_PointCloud_to_PointCloud2 SAPObject;

  ros::spin();



  return 0;
}
