#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string stopbase_frame_id;
    ros::init(argc, argv, "stopbase");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", stopbase_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("stopbase_marker", 100);
    
    ROS_INFO("Stop sign 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker stopbase_marker;
    stopbase_marker.header.frame_id = stopbase_frame_id;
    stopbase_marker.id = 0;
    stopbase_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    stopbase_marker.action = visualization_msgs::Marker::ADD;
    
    stopbase_marker.scale.x = 1;
    stopbase_marker.scale.y = 1;
    stopbase_marker.scale.z = 1;

    stopbase_marker.color.r = 0.92f;
    stopbase_marker.color.g = 0.10f;
    stopbase_marker.color.b = 0.14f;
    stopbase_marker.color.a = 1.0;

    stopbase_marker.lifetime = ros::Duration();

    stopbase_marker.mesh_resource = "package://rviz_markers/stl/StopSign.stl";

    while(ros::ok()) 
    {
        stopbase_marker.header.stamp = ros::Time::now();
        stopbase_marker.lifetime = ros::Duration();
        marker_pub.publish(stopbase_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
