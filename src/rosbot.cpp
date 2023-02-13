#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
    std::string rosbot_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("rosbot_3d");
    node->declare_parameter<std::string>("rosbot_frame_id", "base_link");

    node->get_parameter("rosbot_frame_id", rosbot_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("rosbot_marker", 100);
    rclcpp::Rate loop_rate(40);

    visualization_msgs::msg::Marker rosbot_marker;
    rosbot_marker.header.frame_id = rosbot_frame_id;
    rosbot_marker.id = 0;
    rosbot_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    rosbot_marker.action = visualization_msgs::msg::Marker::ADD;

    rosbot_marker.scale.x = 1;
    rosbot_marker.scale.y = 1;
    rosbot_marker.scale.z = 1;

    rosbot_marker.color.r = 0.6f;
    rosbot_marker.color.g = 0.6f;
    rosbot_marker.color.b = 0.6f;
    rosbot_marker.color.a = 1.0;

    rosbot_marker.mesh_resource = "package://rviz_markers/stl/rosbot.stl";

    while(rclcpp::ok()) 
    {
        marker_pub->publish(rosbot_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
