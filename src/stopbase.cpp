#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv)
{
    std::string stopbase_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("stopbase_3d");
    node->declare_parameter<std::string>("stopbase_frame_id", "base_link");
    auto qos = rclcpp::QoS(100);

    node->get_parameter("stopbase_frame_id", stopbase_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("stopbase_marker", qos);
    rclcpp::Rate loop_rate(40);
    visualization_msgs::msg::Marker stopbase_marker;
    stopbase_marker.header.frame_id = stopbase_frame_id;
    stopbase_marker.id = 0;
    stopbase_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    stopbase_marker.action = visualization_msgs::msg::Marker::ADD;
    
    stopbase_marker.scale.x = 1;
    stopbase_marker.scale.y = 1;
    stopbase_marker.scale.z = 1;

    stopbase_marker.color.r = 0.92f;
    stopbase_marker.color.g = 0.10f;
    stopbase_marker.color.b = 0.14f;
    stopbase_marker.color.a = 1.0;

    stopbase_marker.mesh_resource = "package://rviz_markers/stl/StopSign.stl";

    marker_pub->publish(stopbase_marker); 

    while(rclcpp::ok())
    {
        stopbase_marker.header.stamp = node->now();
        marker_pub->publish(stopbase_marker);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
