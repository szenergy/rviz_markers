#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string loomo_frame_id;
    ros::init(argc, argv, "loomo_3d");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", loomo_frame_id, "loomo_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("loomo_marker", 100);
    
    ROS_INFO("Loomo 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker loomo_marker;
    loomo_marker.header.frame_id = loomo_frame_id;
    loomo_marker.id = 0;
    loomo_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    loomo_marker.action = visualization_msgs::Marker::ADD;

    loomo_marker.scale.x = 1;
    loomo_marker.scale.y = 1;
    loomo_marker.scale.z = 1;

    loomo_marker.color.r = 0.8f;
    loomo_marker.color.g = 0.8f;
    loomo_marker.color.b = 0.8f;
    loomo_marker.color.a = 1.0;

    loomo_marker.lifetime = ros::Duration();

    loomo_marker.mesh_resource = "package://rviz_markers/stl/loomo.stl";

    while(ros::ok()) 
    {
        loomo_marker.header.stamp = ros::Time::now();
        loomo_marker.lifetime = ros::Duration();
        marker_pub.publish(loomo_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
