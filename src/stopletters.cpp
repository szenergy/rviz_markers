#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string stopletters_frame_id;
    ros::init(argc, argv, "stopletters");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", stopletters_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("stopletters_marker", 100);
    
    ROS_INFO("Stop letters 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker stopletters_marker;
    stopletters_marker.header.frame_id = stopletters_frame_id;
    stopletters_marker.id = 0;
    stopletters_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    stopletters_marker.action = visualization_msgs::Marker::ADD;
    
    stopletters_marker.scale.x = 1;
    stopletters_marker.scale.y = 1;
    stopletters_marker.scale.z = 1;

    stopletters_marker.color.r = 1.0f;
    stopletters_marker.color.g = 1.0f;
    stopletters_marker.color.b = 1.0f;
    stopletters_marker.color.a = 1.0;

    stopletters_marker.lifetime = ros::Duration();

    stopletters_marker.mesh_resource = "package://rviz_markers/stl/StopLetters.stl";

    while(ros::ok()) 
    {
        stopletters_marker.header.stamp = ros::Time::now();
        stopletters_marker.lifetime = ros::Duration();
        marker_pub.publish(stopletters_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
