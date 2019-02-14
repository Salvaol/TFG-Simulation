#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <gazebo_msgs/ModelState.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>





void Callback(const gazebo_msgs::ModelStateConstPtr& msg){


   static tf::TransformBroadcaster br;

   geometry_msgs::Pose pose;
   geometry_msgs::Twist twist;

   pose = msg->pose;
   twist = msg->twist;

  tf::Transform transform;
  transform.setOrigin( tf::Vector3(pose.position.x, pose.position.y, pose.position.z) );
	tf::Quaternion q(pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w);
	transform.setRotation(q);
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "base_link"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe("/gazebo/ModelSate", 10, &Callback);

  ros::spin();
  return 0;
};
