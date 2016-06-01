#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <iostream>
#include <vector>

class DHandJointStateRePublisher{
public:
  DHandJointStateRePublisher(ros::NodeHandle &nh);
private:
  void jointstateCallback(const sensor_msgs::JointState::ConstPtr& js);

  ros::Subscriber js_sub;
  ros::Publisher js_pub;

  std::vector<std::string> dhand_joint_name;
};

DHandJointStateRePublisher::DHandJointStateRePublisher(ros::NodeHandle &nh)
{
  dhand_joint_name.push_back("dhand_finger_base_left_joint");
  dhand_joint_name.push_back("dhand_finger_base_right_joint");
  dhand_joint_name.push_back("dhand_finger_middle_left_joint");
  dhand_joint_name.push_back("dhand_finger_middle_middle_joint");
  dhand_joint_name.push_back("dhand_finger_middle_right_joint");
  dhand_joint_name.push_back("dhand_finger_top_left_joint");
  dhand_joint_name.push_back("dhand_finger_top_middle_joint");
  dhand_joint_name.push_back("dhand_finger_top_right_joint");
															 
  ros::NodeHandle n("~");
  js_pub = nh.advertise<sensor_msgs::JointState>(n.param<std::string>("joint_state_republish_topic_name", "/joint_states_republish"), 1);
  js_sub = nh.subscribe<sensor_msgs::JointState>(n.param<std::string>("joint_state_subscribe_topic_name", "/joint_states"), 10, &DHandJointStateRePublisher::jointstateCallback, this);
}

void DHandJointStateRePublisher::jointstateCallback(const sensor_msgs::JointState::ConstPtr& js)
{
  sensor_msgs::JointState joint_state;
  joint_state.header = js->header;
  joint_state.name = js->name;
  joint_state.position = js->position;
  joint_state.velocity = js->velocity;
  joint_state.effort = js->effort;

  for(int i=0; i<dhand_joint_name.size(); i++){
	joint_state.name.push_back(dhand_joint_name[i]);
	joint_state.position.push_back(0);
	joint_state.velocity.push_back(0);
	joint_state.effort.push_back(0);
  }

  js_pub.publish(joint_state);
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "dhand_joint_state_republisher");
  ros::NodeHandle n;
  DHandJointStateRePublisher dhand_joint_state_republisher(n);
  ros::spin();
  return 0;
}
