#include <sstream>
#include <chrono>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <ament_index_cpp/get_package_share_directory.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


int main(int argc, char** argv)
{
    std::string nissan_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("nissan_3d");
    node->declare_parameter<std::string>("nissan_frame_id", "base_link");
    auto qos = rclcpp::QoS(100);
    node->get_parameter("nissan_frame_id", nissan_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("nissan_marker", qos);
    rclcpp::Rate loop_rate(40);
    visualization_msgs::msg::Marker nissan_marker;
    nissan_marker.header.frame_id = nissan_frame_id;
    nissan_marker.header.stamp = node->now();
    nissan_marker.id = 0;
    nissan_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    nissan_marker.action = visualization_msgs::msg::Marker::ADD;

    nissan_marker.scale.x = 1;
    nissan_marker.scale.y = 1;
    nissan_marker.scale.z = 1;

    nissan_marker.color.r = 0.8f;
    nissan_marker.color.g = 0.8f;
    nissan_marker.color.b = 0.8f;
    nissan_marker.color.a = 1.0;

    nissan_marker.mesh_resource = "package://rviz_markers/stl/nissan.stl";

    while(rclcpp::ok())
    {
        nissan_marker.header.stamp = node->now();
        marker_pub->publish(nissan_marker);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
