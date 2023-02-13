#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
    std::string stopletters_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("stoppletters_3d");
    node->declare_parameter<std::string>("stopletters_frame_id", "base_link");

    node->get_parameter("stopletters_frame_id", stopletters_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("stopletters_marker", 100);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker stopletters_marker;
    stopletters_marker.header.frame_id = stopletters_frame_id;
    stopletters_marker.id = 0;
    stopletters_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    stopletters_marker.action = visualization_msgs::msg::Marker::ADD;
    
    stopletters_marker.scale.x = 1;
    stopletters_marker.scale.y = 1;
    stopletters_marker.scale.z = 1;

    stopletters_marker.color.r = 1.0f;
    stopletters_marker.color.g = 1.0f;
    stopletters_marker.color.b = 1.0f;
    stopletters_marker.color.a = 1.0;

    stopletters_marker.mesh_resource = "package://rviz_markers/stl/StopLetters.stl";

    while(rclcpp::ok()) 
    {
        stopletters_marker.header.stamp = node->now();
        marker_pub->publish(stopletters_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
