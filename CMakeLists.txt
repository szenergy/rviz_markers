cmake_minimum_required(VERSION 3.8)
project(rviz2_markers)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

include_directories(
  include 
  "/usr/local/include"
)

set(ament_dependencies
rclcpp
rclcpp_components
visualization_msgs
tf2
tf2_msgs
tf2_geometry_msgs
)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

add_executable(drone src/drone.cpp)
add_executable(egolf src/egolf.cpp)
add_executable(nissan src/nissan.cpp)
add_executable(rosbot src/rosbot.cpp)
add_executable(lexus src/lexus.cpp)
add_executable(turtlecar src/turtlecar.cpp)
add_executable(loomo src/loomo.cpp)
add_executable(stopbase src/stopbase.cpp)
add_executable(stopletters src/stopletters.cpp)
add_executable(cone src/cone.cpp)

ament_target_dependencies(egolf ${ament_dependencies})
target_link_libraries(egolf
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(drone ${ament_dependencies})
target_link_libraries(drone 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(lexus ${ament_dependencies})
target_link_libraries(lexus 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(cone ${ament_dependencies})
target_link_libraries(cone 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(loomo ${ament_dependencies})
target_link_libraries(loomo 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(nissan ${ament_dependencies})
target_link_libraries(nissan 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(rosbot ${ament_dependencies})
target_link_libraries(rosbot
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(stopbase ${ament_dependencies})
target_link_libraries(stopbase 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

ament_target_dependencies(stopletters ${ament_dependencies})
target_link_libraries(stopletters 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)

#ament_target_dependencies(traffic_light ${ament_dependencies})
#target_link_libraries(traffic_light 
#  "sbp"
#  "rclcpp"
#  "rclcpp_components"
#  "visualization_msgs"
#  "tf2"
#  "tf2_msgs"
#  "tf2_geometry_msgs"
#)

ament_target_dependencies(turtlecar ${ament_dependencies})
target_link_libraries(turtlecar 
  "sbp"
  "rclcpp"
  "rclcpp_components"
  "visualization_msgs"
  "tf2"
  "tf2_msgs"
  "tf2_geometry_msgs"
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS cone drone egolf lexus loomo nissan rosbot stopbase stopletters turtlecar
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include/${PROJECT_NAME}
)


install (DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
