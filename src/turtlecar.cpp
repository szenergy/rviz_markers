#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
    std::string turtlecar_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("turtlecar_3d");

    node->declare_parameter<std::string>("turtlecar_frame_id", "base_link");

    node->get_parameter("turtlecar_frame_id", turtlecar_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("turtlecar_marker", 100);
    rclcpp::Rate loop_rate(40);
    visualization_msgs::msg::Marker turtlecar_marker;
    turtlecar_marker.header.frame_id = turtlecar_frame_id;
    turtlecar_marker.id = 0;
    turtlecar_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    turtlecar_marker.action = visualization_msgs::msg::Marker::ADD;
    
    turtlecar_marker.scale.x = 1;
    turtlecar_marker.scale.y = 1;
    turtlecar_marker.scale.z = 1;

    turtlecar_marker.color.r = 0.6f;
    turtlecar_marker.color.g = 0.6f;
    turtlecar_marker.color.b = 0.6f;
    turtlecar_marker.color.a = 1.0;

    turtlecar_marker.mesh_resource = "package://rviz_markers/stl/TurtleCar.stl";

    while(rclcpp::ok()) 
    {
        marker_pub->publish(turtlecar_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
}
