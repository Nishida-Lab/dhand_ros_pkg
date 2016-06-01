cmake_minimum_required(VERSION 2.8.3)
project(dhand_control)

find_package(catkin REQUIRED COMPONENTS
  control_msgs
  roscpp
  sensor_msgs
  )

catkin_package(CATKIN_DEPENDS
  roscpp
  sensor_msgs
  )
include_directories(
  ${catkin_INCLUDE_DIRS}
  )

add_executable(dhand_joint_state_republisher src/dhand_joint_state_republisher.cpp)

add_dependencies(dhand_joint_state_republisher dhand_joint_state_republisher_cpp)

target_link_libraries(dhand_joint_state_republisher
  ${catkin_LIBRARIES}
  )

