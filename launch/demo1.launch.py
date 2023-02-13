from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():

    #pkg_name = 'lexus_bringup'
    #pkg_dir = os.popen('/bin/bash -c "source /usr/share/colcon_cd/function/colcon_cd.sh && colcon_cd %s && pwd"' % pkg_name).read().strip()


    return LaunchDescription([
        Node(
            package='tf2_ros',
            #namespace='lexus3',
            executable='static_transform_publisher',
            name='drone_f_tf',
            output='screen',
            ##  Old-style arguments are deprecated, parameters should be used, but this does not work TODO
            arguments=['1.0', '2.5', '1.2', '3.1415926535', '0.0' '0.0','map','fake_drone'],
            #parameters=[{'translation.x': 697237.0, 'translation.y': 5285644.0, 'translation.z': 0.0, 'rotation.x': 0.0, 'rotation.y': 0.0, 'rotation.z': 0.0, 'rotation.w': 1.0, 'frame_id': 'map', 'child_frame_id': 'map_gyor_0'}]
        ),
        Node(
            package='tf2_ros',
            #namespace='lexus3',
            executable='static_transform_publisher',
            name='golf_f_tf',
            output='screen',
            arguments=['639770.0', '5195040.0', '0.0','0', '0', '0', '1','map','fake_golf'],
        )#,
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='duro_gps_tf_publisher',
        #     output='screen',
        #     arguments=['1.6', '0.0', '0.2','0', '0', '0', '1','base_link','duro_gps'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='zed_camera_front_tf_publisher',
        #     output='screen',
        #     arguments=['1.6', '0.0', '1.286','0', '0', '0', '1','base_link','zed_camera_front'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='duro_gps_imu_tf_publisher',
        #     output='screen',
        #     arguments=['0.0', '0.0', '0.2','0', '0', '0', '1','base_link','duro_gps_imu'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='base_link_ground_link_publisher',
        #     output='screen',
        #     arguments=['0.0', '0.0', '-0.37','0', '0', '0', '1','base_link','ground_link'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='left1_os_front_tf_publisher',
        #     output='screen',
        #     arguments=['1.6', '0.5', '1.3','3.14159', '0', '0', 'base_link','os_left_a'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='right1_os_front_tf_publisher',
        #     output='screen',
        #     arguments=['1.53', '-0.5', '1.41','3.14159', '0', '0','base_link','os_right_a'],
        # ),
        # Node(
        #     package='tf2_ros',
        #     #namespace='lexus3',
        #     executable='static_transform_publisher',
        #     name='center1_os_front_tf_publisher',
        #     output='screen',
        #     arguments=['0.75', '0.0', '1.91','3.14159', '0', '0','base_link','os_center_a'],
        # )
    ])