#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string turtlecar_frame_id;
    ros::init(argc, argv, "turtlecar");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", turtlecar_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("turtlecar_marker", 100);
    
    ROS_INFO("TurtleCar 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker turtlecar_marker;
    turtlecar_marker.header.frame_id = turtlecar_frame_id;
    turtlecar_marker.id = 0;
    turtlecar_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    turtlecar_marker.action = visualization_msgs::Marker::ADD;
    
    turtlecar_marker.scale.x = 1;
    turtlecar_marker.scale.y = 1;
    turtlecar_marker.scale.z = 1;

    turtlecar_marker.color.r = 0.6f;
    turtlecar_marker.color.g = 0.6f;
    turtlecar_marker.color.b = 0.6f;
    turtlecar_marker.color.a = 1.0;

    turtlecar_marker.lifetime = ros::Duration();

    turtlecar_marker.mesh_resource = "package://rviz_markers/stl/TurtleCar.stl";

    while(ros::ok()) 
    {
        turtlecar_marker.header.stamp = ros::Time::now();
        turtlecar_marker.lifetime = ros::Duration();
        marker_pub.publish(turtlecar_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
