cmake_minimum_required(VERSION 3.8)
project(rviz_markers)

set(CMAKE_CXX_STANDARD 17)

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

#include_directories(
#  include 
#  "/usr/local/include"
#)

set(ament_dependencies
  rclcpp
  rclcpp_components
  visualization_msgs
  tf2
  tf2_msgs
  tf2_geometry_msgs
)

#link_directories("/usr/local/lib/")
#include_directories("/usr/local/include/")

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

ament_target_dependencies(egolf rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(drone rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(lexus rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(cone rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(loomo rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(nissan rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(rosbot rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(stopbase rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(stopletters rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
ament_target_dependencies(turtlecar rclcpp rclcpp_components visualization_msgs tf2 tf2_msgs tf2_geometry_msgs)
# target_link_libraries(egolf
#   "rclcpp"
#   "rclcpp_components"
#   "visualization_msgs"
#   "tf2"
#   "tf2_msgs"
#   "tf2_geometry_msgs"
# )

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

install (DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS cone drone egolf lexus loomo nissan rosbot stopbase stopletters turtlecar
  DESTINATION lib/${PROJECT_NAME}
)

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}
#   DESTINATION include/${PROJECT_NAME}
# )

ament_package()
