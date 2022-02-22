#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


geometry_msgs::Pose location;
std::string drone_frame_id;


int main( int argc, char** argv )
{
    bool substate=true;

    location.position.x = 0;
    location.position.y = 0;
    location.position.z = 0;
    
    location.orientation.x = 0;
    location.orientation.y = 0;
    location.orientation.z = 0;
    location.orientation.w = 1;
    
    ros::init(argc, argv, "drone_3d");
    ros::NodeHandle n("~");

    n.param<std::string>("frame_id", drone_frame_id, "drone_link");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("drone_marker", 100);
    
    ROS_INFO("Drone 3D model published");

    ros::Rate rate(40);

    visualization_msgs::Marker drone_marker;

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    drone_marker.header.frame_id = drone_frame_id;
        
    //drone_marker.ns = "drone_base";
    drone_marker.id = 0;

    drone_marker.type = visualization_msgs::Marker::MESH_RESOURCE;

    drone_marker.action = visualization_msgs::Marker::ADD;

    drone_marker.pose.position.x = 0;
    drone_marker.pose.position.y = 0;
    drone_marker.pose.position.z = 0;

    drone_marker.pose.orientation.x = 0;
    drone_marker.pose.orientation.y = 0;
    drone_marker.pose.orientation.z = 0;
    drone_marker.pose.orientation.w = 0;

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
        
        transform.setOrigin( tf::Vector3(location.position.x,location.position.y,location.position.z) );
        transform.setRotation(tf::Quaternion(location.orientation.x,location.orientation.y,location.orientation.z,location.orientation.w));
        
        ros::spinOnce();
        rate.sleep();
    }
}
