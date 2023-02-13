#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
    std::string lexus_frame_id;
    bool foxglove_rotation;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("lexus_3d");
    node->declare_parameter<std::string>("lexus_frame_id", "base_link");
    node->get_parameter("lexus_frame_id", lexus_frame_id);

    node->declare_parameter<bool>("foxglove_rotation", false);
    node->get_parameter("foxglove_rotation", foxglove_rotation);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("lexus_marker", 100);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker lexus_marker;
    lexus_marker.header.frame_id = lexus_frame_id;
    lexus_marker.id = 0;
    lexus_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    lexus_marker.action = visualization_msgs::msg::Marker::ADD;
   
    lexus_marker.scale.x = 1;
    lexus_marker.scale.y = 1;
    lexus_marker.scale.z = 1;

    lexus_marker.color.r = 0.8f;
    lexus_marker.color.g = 0.8f;
    lexus_marker.color.b = 0.8f;
    lexus_marker.color.a = 1.0;
    if(foxglove_rotation){

        lexus_marker.pose.orientation.x = -0.707;
        lexus_marker.pose.orientation.y = 0.0;
        lexus_marker.pose.orientation.z = 0.0;
        lexus_marker.pose.orientation.w = 0.707;
    }
    else{
        lexus_marker.pose.orientation.x = 0.0;
        lexus_marker.pose.orientation.y = 0.0;
        lexus_marker.pose.orientation.z = 0.0;
        lexus_marker.pose.orientation.w = 1.0;       
    }

    lexus_marker.mesh_resource = "package://rviz_markers/stl/lexus.stl";

    while(rclcpp::ok()) 
    {
        marker_pub->publish(lexus_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
