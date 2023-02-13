#include <chrono>
#include <functional>
#include <memory>
#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
    std::string loomo_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("loomo_3d");

    node->declare_parameter<std::string>("loomo_frame_id", "base_link");

    node->get_parameter("loomo_frame_id", loomo_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("loomo_marker", 100);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker loomo_marker;
    loomo_marker.header.frame_id = loomo_frame_id;
    loomo_marker.id = 0;
    loomo_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    loomo_marker.action = visualization_msgs::msg::Marker::ADD;

    loomo_marker.scale.x = 1;
    loomo_marker.scale.y = 1;
    loomo_marker.scale.z = 1;

    loomo_marker.color.r = 0.8f;
    loomo_marker.color.g = 0.8f;
    loomo_marker.color.b = 0.8f;
    loomo_marker.color.a = 1.0;

    loomo_marker.mesh_resource = "package://rviz_markers/stl/loomo.stl";

    while(rclcpp::ok()) 
    {
        marker_pub->publish(loomo_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
}
