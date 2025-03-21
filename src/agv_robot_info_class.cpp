#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
                           std::string serial, std::string ip,
                           std::string firm_ver, int max_load)
    : RobotInfo(node_handle, desc, serial, ip, firm_ver) {

  maximum_payload = max_load;
}

void AGVRobotInfo::publish_data() {

  robotinfo_msgs::RobotInfo10Fields msg_to_pub;
  msg_to_pub.data_field_01 = "robot_description: " + robot_description;
  msg_to_pub.data_field_02 = "serial_number: " + serial_number;
  msg_to_pub.data_field_03 = "ip_address: " + ip_address;
  msg_to_pub.data_field_04 = "firmware_version: " + firmware_version;
  msg_to_pub.data_field_05 =
      "maximum_payload: " + std::to_string(maximum_payload) + " Kg";

  info_publisher.publish(msg_to_pub);
}