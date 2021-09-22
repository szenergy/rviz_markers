#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <geometry_msgs/Pose.h>
#include <tf/transform_broadcaster.h>


int state=6;
geometry_msgs::Pose location;

void set_state(const std_msgs::String::ConstPtr& msg)
{
    std::string read;
    read=msg->data.c_str();
    state= read[0]-'0';
    printf("%d",state);
}

void change_placement(const geometry_msgs::Pose& msg)
{
    location=msg;
}

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
    
    ros::init(argc, argv, "traffic_light");
    ros::NodeHandle n("~");

    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("Marker", 100);
    
    ros::Subscriber sub1 = n.subscribe("traffic_light_state", 1000,set_state);
    ros::Subscriber sub2 = n.subscribe("traffic_light_placement", 1000,change_placement);
    
    ros::Rate rate(10);

    visualization_msgs::Marker box_marker,light_marker,light1_marker;

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    light1_marker.header.frame_id = n.getNamespace();
    
    light_marker.header.frame_id = n.getNamespace();
    
    box_marker.header.frame_id = n.getNamespace();
        
    box_marker.ns = "box";
    box_marker.id = 0;

    box_marker.type = visualization_msgs::Marker::MESH_RESOURCE;

    box_marker.action = visualization_msgs::Marker::ADD;

    box_marker.pose.position.x = 0;
    box_marker.pose.position.y = 0;
    box_marker.pose.position.z = 0;

    box_marker.pose.orientation.x = 0.707;
    box_marker.pose.orientation.y = 0;
    box_marker.pose.orientation.z = 0;
    box_marker.pose.orientation.w = 0.707;

    box_marker.scale.x = 0.01;
    box_marker.scale.y = 0.01;
    box_marker.scale.z = 0.01;

    box_marker.color.r = 0.5f;
    box_marker.color.g = 0.5f;
    box_marker.color.b = 0.5f;
    box_marker.color.a = 1.0;

    box_marker.lifetime = ros::Duration();

    box_marker.mesh_resource = "package://traffic_light/stl/box.stl";

    light_marker.ns = "light1";
    light_marker.id = 1;

    light_marker.type = visualization_msgs::Marker::MESH_RESOURCE;

    light_marker.action = visualization_msgs::Marker::ADD;

    light_marker.color.b = 0.0f;
    light_marker.color.a = 1.0;

    light_marker.mesh_resource = "package://traffic_light/stl/light.stl";
    
    light_marker.pose.position.x = 0;
    light_marker.pose.position.y = -0.001;

    light_marker.pose.orientation.x = 0.707;
    light_marker.pose.orientation.y = 0;
    light_marker.pose.orientation.z = 0;
    light_marker.pose.orientation.w = 0.707;

    light_marker.scale.x = 0.01;
    light_marker.scale.y = 0.01;
    light_marker.scale.z = 0.01;

    light1_marker.color.a = 1.0f;
    
    light1_marker.ns = "light2";
    light1_marker.id = 2;
    light1_marker.type = visualization_msgs::Marker::MESH_RESOURCE;

    light1_marker.action = visualization_msgs::Marker::ADD;

    light1_marker.pose.position.x = 0;
    light1_marker.pose.position.y = -0.001;
    light1_marker.pose.position.z = 0.1;

    light1_marker.pose.orientation.x = 0.707;
    light1_marker.pose.orientation.y = 0;
    light1_marker.pose.orientation.z = 0;
    light1_marker.pose.orientation.w = 0.707;

    light1_marker.scale.x = 0.01;
    light1_marker.scale.y = 0.01;
    light1_marker.scale.z = 0.01;
    
    light1_marker.color.a = 1.0f;

    light1_marker.mesh_resource = "package://traffic_light/stl/light1.stl";
       
    while(ros::ok()) 
    {

        box_marker.header.stamp = ros::Time::now();
        light_marker.header.stamp = ros::Time::now();
        light1_marker.header.stamp = ros::Time::now();
        
        switch (state){
            {case 1:
                light_marker.color.r = 1.0f;
                light_marker.color.g = 0.0f;
                light_marker.color.b = 0.0f;
                light_marker.pose.position.z = 0.2;
    
    
                light1_marker.color.r = 0.5f;
                light1_marker.color.g = 0.5f;
                light1_marker.color.b = 0.5f;
            break;}
            {case 2:
                light_marker.color.r = 1.0f;
                light_marker.color.g = 0.0f;
                light_marker.color.b = 0.0f;
                light_marker.pose.position.z = 0.2;
    
                light1_marker.color.a = 1.0f;
                light1_marker.color.r = 1.0f;
                light1_marker.color.g = 1.0f;
                light1_marker.color.b = 0.0f;
    
            break;}
            {case 3:
                light_marker.color.r = 0.0f;
                light_marker.color.g = 1.0f;
                light_marker.color.b = 0.0f;
                light_marker.pose.position.z = 0.0;
    
    
                light1_marker.color.r = 0.5f;
                light1_marker.color.g = 0.5f;
                light1_marker.color.b = 0.5f;
            break;}
            {case 4:
                light_marker.color.r = 0.5f;
                light_marker.color.g = 0.5f;
                light_marker.color.b = 0.5f;
    
                light1_marker.color.r = 1.0f;
                light1_marker.color.g = 1.0f;
                light1_marker.color.b = 0.0f;
            break;}
            {case 5:
                light_marker.color.r = 0.5f;
                light_marker.color.g = 0.5f;
                light_marker.color.b = 0.5f;
    
                if (substate == true)
                {     
                substate = false;
                light1_marker.color.r = 1.0f;
                light1_marker.color.g = 1.0f;
                light1_marker.color.b = 0.0f;
                }
                else
                {
                light1_marker.color.r = 0.5f;
                light1_marker.color.g = 0.5f;
                light1_marker.color.b = 0.5f;
                substate = true;
                }
                break;}
            {case 6:
                light_marker.color.r = 0.5f;
                light_marker.color.g = 0.5f;
                light_marker.color.b = 0.5f;
    
                light1_marker.color.r = 0.5f;
                light1_marker.color.g = 0.5f;
                light1_marker.color.b = 0.5f;
            break;}
        }
        
        light_marker.lifetime = ros::Duration();
        light1_marker.lifetime = ros::Duration();
        box_marker.lifetime = ros::Duration();
    
        marker_pub.publish(light1_marker);
        marker_pub.publish(box_marker);
        marker_pub.publish(light_marker);
        
        transform.setOrigin( tf::Vector3(location.position.x,location.position.y,location.position.z) );
        transform.setRotation(tf::Quaternion(location.orientation.x,location.orientation.y,location.orientation.z,location.orientation.w));
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", n.getNamespace()));
        
        ros::spinOnce();
        rate.sleep();
    }
}