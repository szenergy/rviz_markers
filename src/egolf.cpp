#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>



int main( int argc, char** argv )
{
    std::string golf_frame_id;
    ros::init(argc, argv, "egolf_3d");
    ros::NodeHandle n("~");
    n.param<std::string>("frame_id", golf_frame_id, "base_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("egolf_marker", 100);
    
    ROS_INFO("E-golf 3D model published");

    ros::Rate rate(40);

    visualization_msgs::Marker golf_marker;

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    golf_marker.header.frame_id = golf_frame_id;
    golf_marker.id = 0;
    golf_marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    golf_marker.action = visualization_msgs::Marker::ADD;
    golf_marker.pose.position.x = 0;
    golf_marker.pose.position.y = 0;
    golf_marker.pose.position.z = 0;

    golf_marker.pose.orientation.x = 0.707;
    golf_marker.pose.orientation.y = 0;
    golf_marker.pose.orientation.z = 0;
    golf_marker.pose.orientation.w = 0.707;

    golf_marker.scale.x = 0.01;
    golf_marker.scale.y = 0.01;
    golf_marker.scale.z = 0.01;

    golf_marker.color.r = 0.6f;
    golf_marker.color.g = 0.6f;
    golf_marker.color.b = 0.6f;
    golf_marker.color.a = 1.0;

    golf_marker.lifetime = ros::Duration();

    golf_marker.mesh_resource = "package://rviz_markers/stl/egolf.stl";

    while(ros::ok()) 
    {
        golf_marker.header.stamp = ros::Time::now();
        golf_marker.lifetime = ros::Duration();
        marker_pub.publish(golf_marker);
        ros::spinOnce();
        rate.sleep();
    }
}