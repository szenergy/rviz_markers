# 3D Markers for Rviz

## Overview
This is a collection of low-poly 3D markers that can enhance data visualisation using Rviz. The 3D models are designed to be lightweight without heavily compromising realisticity.

## Installation

1. Clone this repository to your catkin workspace `src`
2. Build the package
`cd ~/catkin_ws`
`catkin build rviz_markers`
3. Source your workspace
`source ~/catkin_ws/devel/setup.bash`

## Usage

## Simple demo

Simply run:
```
roslaunch rviz_markers demo1.launch 
```
This will start `rviz`, publis some TF frames and start all markers, visible in `rviz`.

The package currently contains two markers. 
### VW E-Golf
Using the VW E-Golf marker:
1. In a terminal window, start roscore
`roscore`
2. In a different terminal window, run:
`rosrun rviz_markers egolf _golf_frame_id:=fake_golf`

3. The marker should be visible using Rviz, as Marker, choose `fake_golf` frame id. 

![](img/egolf01.png)

### DJI Matrice 600 Pro Drone
Using the DJI Matrice 600 Pro Drone marker:
1. In a terminal window, start roscore
`roscore`
2. In a different terminal window, run:
`rosrun rviz_markers drone`
3. The marker should be visible using Rviz, as Marker. 

![](img/drone01.png)

## Topics
### VW E-Golf
Parameters of the published topic:
* Name: *egolf_marker*
* Type: *visualisation_msgs/Marker*
* Fixed frame: *base_link* (set with `golf_frame_id`)

### DJI Matrice 600 Pro Drone
Parameters of the published topic:
* Name: *drone_marker*
* Type: *visualisation_msgs/Marker*
* Frame: set with `drone_frame_id`

