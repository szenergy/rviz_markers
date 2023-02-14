#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv)
{
    std::string lexus_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("lexus_3d");
    node->declare_parameter<std::string>("lexus_frame_id", "base_link");
    auto qos = rclcpp::QoS(100);
    node->get_parameter("lexus_frame_id", lexus_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("lexus_marker", qos);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker lexus_marker;
    lexus_marker.header.frame_id = lexus_frame_id;
    lexus_marker.id = 0;
    lexus_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    lexus_marker.action = visualization_msgs::msg::Marker::ADD;
    
    lexus_marker.scale.x = 1;
    lexus_marker.scale.y = 1;
    lexus_marker.scale.z = 1;

    lexus_marker.color.r = 0.6f;
    lexus_marker.color.g = 0.6f;
    lexus_marker.color.b = 0.6f;
    lexus_marker.color.a = 1.0;

    lexus_marker.mesh_resource = "package://rviz_markers/stl/lexus.stl";

    while(rclcpp::ok())
    {
        lexus_marker.header.stamp = node->now();
        marker_pub->publish(lexus_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
