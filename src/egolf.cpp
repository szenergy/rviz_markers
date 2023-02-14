#include <sstream>
#include <chrono>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <ament_index_cpp/get_package_share_directory.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv)
{
    std::string golf_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("egolf_3d");
    node->declare_parameter<std::string>("golf_frame_id", "base_link");
    auto qos = rclcpp::QoS(100);
    node->get_parameter("golf_frame_id", golf_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("golf_marker", qos);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker golf_marker;
    golf_marker.header.frame_id = golf_frame_id;
    golf_marker.header.stamp = node->now();
    golf_marker.id = 0;
    golf_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    golf_marker.action = visualization_msgs::msg::Marker::ADD;
    
    golf_marker.scale.x = 1;
    golf_marker.scale.y = 1;
    golf_marker.scale.z = 1;

    golf_marker.color.r = 0.6f;
    golf_marker.color.g = 0.6f;
    golf_marker.color.b = 0.6f;
    golf_marker.color.a = 1.0;

    golf_marker.mesh_resource = "package://rviz_markers/stl/egolf.stl";

    while(rclcpp::ok())
    {
        golf_marker.header.stamp = node->now();
        marker_pub->publish(golf_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
