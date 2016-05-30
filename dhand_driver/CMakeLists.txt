cmake_minimum_required(VERSION 2.8.3)
project(dhand_driver)

find_package(catkin REQUIRED COMPONENTS
  rospy
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
