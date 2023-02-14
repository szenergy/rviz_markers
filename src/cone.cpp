#include <sstream>
#include <chrono>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <ament_index_cpp/get_package_share_directory.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main( int argc, char** argv )
{
    std::string cone_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("cone");
    node->declare_parameter<std::string>("cone_frame_id", "base_link");
    auto qos = rclcpp::QoS(100);
    node->get_parameter("cone_frame_id", cone_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("cone_marker", qos);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker cone_marker;
    cone_marker.header.frame_id = cone_frame_id;
    cone_marker.header.stamp = node->now();
    cone_marker.id = 0;
    cone_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    cone_marker.action = visualization_msgs::msg::Marker::ADD;
    
    cone_marker.scale.x = 1;
    cone_marker.scale.y = 1;
    cone_marker.scale.z = 1;

    cone_marker.color.r = 0.62f;
    cone_marker.color.g = 0.25f;
    cone_marker.color.b = 0.05f;
    cone_marker.color.a = 1.0;

    cone_marker.mesh_resource = "package://rviz_markers/stl/cone.stl";

    while(rclcpp::ok()) 
    {
        cone_marker.header.stamp = node->now();
        marker_pub->publish(cone_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
