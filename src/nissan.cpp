#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


int main( int argc, char** argv )
{
  
    std::string frame_id;
    ros::init(argc, argv, "nissan_3d");
    ros::NodeHandle n("~");

    n.param<std::string>("frame_id", frame_id, "nissan_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("nissan_marker", 100);
    
    ROS_INFO("Nissan 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker nissan_marker;
    nissan_marker.header.frame_id = frame_id;
    nissan_marker.id = 0;
    nissan_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    nissan_marker.action = visualization_msgs::Marker::ADD;
    nissan_marker.pose.position.x = 0;
    nissan_marker.pose.position.y = 0;
    nissan_marker.pose.position.z = 0;
    nissan_marker.pose.orientation.x = 0.707;
    nissan_marker.pose.orientation.y = 0;
    nissan_marker.pose.orientation.z = 0;
    nissan_marker.pose.orientation.w = 0.707;

    nissan_marker.scale.x = 0.01;
    nissan_marker.scale.y = 0.01;
    nissan_marker.scale.z = 0.01;

    nissan_marker.color.r = 0.8f;
    nissan_marker.color.g = 0.8f;
    nissan_marker.color.b = 0.8f;
    nissan_marker.color.a = 1.0;

    nissan_marker.lifetime = ros::Duration();

    nissan_marker.mesh_resource = "package://rviz_markers/stl/nissan.stl";

    while(ros::ok()) 
    {
        nissan_marker.header.stamp = ros::Time::now();
        nissan_marker.lifetime = ros::Duration();
        marker_pub.publish(nissan_marker);
        ros::spinOnce();
        rate.sleep();
    }
}