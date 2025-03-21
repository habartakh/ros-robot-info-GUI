#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/init.h"
#include "ros/rate.h"

RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::string desc,
                     std::string serial, std::string ip, std::string firm_ver)
    : robot_description(desc), serial_number(serial), ip_address(ip),
      firmware_version(firm_ver) {

  nh = node_handle;
  info_publisher =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 100);
}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg_to_pub;
  msg_to_pub.data_field_01 = "robot_description: " + robot_description;
  msg_to_pub.data_field_02 = "serial_number: " + serial_number;
  msg_to_pub.data_field_03 = "ip_address: " + ip_address;
  msg_to_pub.data_field_04 = "firmware_version: " + firmware_version;

  ros::Rate loop_rate(10);

  info_publisher.publish(msg_to_pub);
}