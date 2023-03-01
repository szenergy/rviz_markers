#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string szemission_frame_id;
    ros::init(argc, argv, "szemission_3d");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", szemission_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("szemission_marker", 100);
    
    ROS_INFO("SZEmission 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker szemission_marker;
    szemission_marker.header.frame_id = szemission_frame_id;
    szemission_marker.id = 0;
    szemission_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    szemission_marker.action = visualization_msgs::Marker::ADD;
    
    szemission_marker.scale.x = 1;
    szemission_marker.scale.y = 1;
    szemission_marker.scale.z = 1;

    szemission_marker.color.r = 0.6f;
    szemission_marker.color.g = 0.6f;
    szemission_marker.color.b = 0.6f;
    szemission_marker.color.a = 1.0;

    szemission_marker.lifetime = ros::Duration();

    szemission_marker.mesh_resource = "package://rviz_markers/stl/SZEmissionRviz5.obj";

    while(ros::ok()) 
    {
        szemission_marker.header.stamp = ros::Time::now();
        szemission_marker.lifetime = ros::Duration();
        marker_pub.publish(szemission_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
