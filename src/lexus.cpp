#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


int main( int argc, char** argv )
{
  
    std::string frame_id;
    ros::init(argc, argv, "lexus_3d");
    ros::NodeHandle n("~");

    n.param<std::string>("frame_id", frame_id, "lexus_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("lexus_marker", 100);
    
    ROS_INFO("Lexus 3D model published");
 
    ros::Rate rate(40);
    visualization_msgs::Marker lexus_marker;
    lexus_marker.header.frame_id = frame_id;
    lexus_marker.id = 0;
    lexus_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    lexus_marker.action = visualization_msgs::Marker::ADD;
    lexus_marker.pose.position.x = 0;
    lexus_marker.pose.position.y = 0;
    lexus_marker.pose.position.z = 0;
    
    lexus_marker.pose.orientation.x = 0;
    lexus_marker.pose.orientation.y = 0;
    lexus_marker.pose.orientation.z = 0;
    lexus_marker.pose.orientation.w = 0;

    lexus_marker.scale.x = 1;
    lexus_marker.scale.y = 1;
    lexus_marker.scale.z = 1;

    lexus_marker.color.r = 0.8f;
    lexus_marker.color.g = 0.8f;
    lexus_marker.color.b = 0.8f;
    lexus_marker.color.a = 1.0;

    lexus_marker.lifetime = ros::Duration();

    lexus_marker.mesh_resource = "package://rviz_markers/stl/lexus.stl";

    while(ros::ok()) 
    {
        lexus_marker.header.stamp = ros::Time::now();
        lexus_marker.lifetime = ros::Duration();
        marker_pub.publish(lexus_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
