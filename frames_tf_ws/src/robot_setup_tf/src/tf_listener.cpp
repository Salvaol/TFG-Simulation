#include <ros/ros.h>
#include <gazebo_msgs/ModelState.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){

  ros::init(argc, argv, "robot_tf_listener");

  ros::NodeHandle n;

  tf::TransformListener listener;

  while (n.ok()){
  tf::StampedTransform world_point;


    try{

      listener.lookupTransform("base_link", "map",ros::Time(0), world_point);
    }
  
      catch (tf::TransformException& ex){
      ROS_ERROR("Received an exception trying to transform a point from \"base_link\" to \"map\": %s", ex.what());
      ros::Duration(1.0).sleep();
      continue;
      }
    



  }
  return 0;
 };
