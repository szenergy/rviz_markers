#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


geometry_msgs::Pose location;

int main( int argc, char** argv )
{

    location.position.x = 0;
    location.position.y = 0;
    location.position.z = 0;
    
    location.orientation.x = 0;
    location.orientation.y = 0;
    location.orientation.z = 0;
    location.orientation.w = 1;
    
    ros::init(argc, argv, "egolf_3d");
    ros::NodeHandle n("~");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("egolf_marker", 100);
    
    ROS_INFO("E-golf 3D model published");

    ros::Rate rate(10);

    visualization_msgs::Marker golf_marker;

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    golf_marker.header.frame_id = "base_link";
        
    golf_marker.ns = "egolf_base";
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

    golf_marker.color.r = 0.5f;
    golf_marker.color.g = 0.5f;
    golf_marker.color.b = 0.5f;
    golf_marker.color.a = 1.0;

    golf_marker.lifetime = ros::Duration();

    golf_marker.mesh_resource = "package://rviz_markers/stl/egolf.stl";

    transform.setOrigin( tf::Vector3(location.position.x,location.position.y,location.position.z) );
    transform.setRotation(tf::Quaternion(location.orientation.x,location.orientation.y,location.orientation.z,location.orientation.w));
    
    while(ros::ok()) 
    {

        golf_marker.header.stamp = ros::Time::now();
        golf_marker.lifetime = ros::Duration();
    
        marker_pub.publish(golf_marker);
        
        ros::spinOnce();
        rate.sleep();
    }
}