cmake_minimum_required(VERSION 2.8.3)
project(dhand_description)
find_package(catkin REQUIRED COMPONENTS
  joint_state_publisher
  robot_state_publisher
)
catkin_package()
