#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>

int main( int argc, char** argv )
{
    std::string rosbot_frame_id;
    ros::init(argc, argv, "rosbot_3d");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", rosbot_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("rosbot_marker", 100);
    
    ROS_INFO("Husarion ROSbot 2.0 Pro 3D model published");

    ros::Rate rate(40);
    visualization_msgs::Marker rosbot_marker;
    rosbot_marker.header.frame_id = rosbot_frame_id;
    rosbot_marker.id = 0;
    rosbot_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    rosbot_marker.action = visualization_msgs::Marker::ADD;

    rosbot_marker.scale.x = 1;
    rosbot_marker.scale.y = 1;
    rosbot_marker.scale.z = 1;

    rosbot_marker.color.r = 0.6f;
    rosbot_marker.color.g = 0.6f;
    rosbot_marker.color.b = 0.6f;
    rosbot_marker.color.a = 1.0;

    rosbot_marker.lifetime = ros::Duration();

    rosbot_marker.mesh_resource = "package://rviz_markers/stl/rosbot.stl";

    while(ros::ok()) 
    {
        rosbot_marker.header.stamp = ros::Time::now();
        rosbot_marker.lifetime = ros::Duration();
        marker_pub.publish(rosbot_marker);
        ros::spinOnce();
        rate.sleep();
    }
}
