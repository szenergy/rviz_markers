#include <sstream>
#include "visualization_msgs/msg/marker.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose.hpp>
#include <tf2_ros/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


int main( int argc, char** argv)
{
    std::string drone_frame_id;
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("drone_3d");
    node->declare_parameter<std::string>("drone_frame_id", "base_link");

    node->get_parameter("drone_frame_id", drone_frame_id);

    auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>("drone_marker", 100);
    rclcpp::Rate loop_rate(40);
    visualization_msgs::msg::Marker drone_marker;
    drone_marker.header.frame_id = drone_frame_id;
    drone_marker.id = 0;
    drone_marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
    drone_marker.action = visualization_msgs::msg::Marker::ADD;

    drone_marker.scale.x = 1;
    drone_marker.scale.y = 1;
    drone_marker.scale.z = 1;

    drone_marker.color.r = 0.5f;
    drone_marker.color.g = 0.5f;
    drone_marker.color.b = 0.5f;
    drone_marker.color.a = 1.0;

    drone_marker.mesh_resource = "package://rviz_markers/stl/drone600.stl";

    while(rclcpp::ok()) 
    {
        drone_marker.header.stamp = node->now();
        marker_pub->publish(drone_marker); 
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    return 0;
}
