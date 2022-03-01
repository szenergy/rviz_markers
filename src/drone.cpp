#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


int main( int argc, char** argv )
{
    std::string drone_frame_id;
    ros::init(argc, argv, "drone_3d");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", drone_frame_id, "drone_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("drone_marker", 100);
    
    ROS_INFO("Drone 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker drone_marker;
    drone_marker.header.frame_id = drone_frame_id;
    drone_marker.id = 0;
    drone_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    drone_marker.action = visualization_msgs::Marker::ADD;

    drone_marker.scale.x = 1;
    drone_marker.scale.y = 1;
    drone_marker.scale.z = 1;

    drone_marker.color.r = 0.5f;
    drone_marker.color.g = 0.5f;
    drone_marker.color.b = 0.5f;
    drone_marker.color.a = 1.0;

    drone_marker.lifetime = ros::Duration();

    drone_marker.mesh_resource = "package://rviz_markers/stl/drone600.stl";

    while(ros::ok()) 
    {
        drone_marker.header.stamp = ros::Time::now();
        drone_marker.lifetime = ros::Duration();
        marker_pub.publish(drone_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
