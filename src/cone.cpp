#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string cone_frame_id;
    ros::init(argc, argv, "cone");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", cone_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("cone_marker", 100);
    
    ROS_INFO("Traffic cone 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker cone_marker;
    cone_marker.header.frame_id = cone_frame_id;
    cone_marker.id = 0;
    cone_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    cone_marker.action = visualization_msgs::Marker::ADD;
    
    cone_marker.scale.x = 1;
    cone_marker.scale.y = 1;
    cone_marker.scale.z = 1;

    cone_marker.color.r = 0.62f;
    cone_marker.color.g = 0.25f;
    cone_marker.color.b = 0.05f;
    cone_marker.color.a = 1.0;

    cone_marker.lifetime = ros::Duration();

    cone_marker.mesh_resource = "package://rviz_markers/stl/cone.stl";

    while(ros::ok()) 
    {
        cone_marker.header.stamp = ros::Time::now();
        cone_marker.lifetime = ros::Duration();
        marker_pub.publish(cone_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
