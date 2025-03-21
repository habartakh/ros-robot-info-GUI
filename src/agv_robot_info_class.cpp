#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string desc,
                           std::string serial, std::string ip,
                           std::string firm_ver, int max_load,
                           HydraulicSystemMonitor &monitor)
    : RobotInfo(node_handle, desc, serial, ip, firm_ver) {

  maximum_payload = max_load;
  hydraulic_system_monitor = monitor;
}

void AGVRobotInfo::set_agv_general_variables(std::string &desc,
                                             std::string &serial,
                                             std::string &ip,
                                             std::string &firm_ver,
                                             int max_load) {

  robot_description = desc;
  serial_number = serial;
  ip_address = ip;
  firmware_version = firm_ver;
  maximum_payload = max_load;
}

void AGVRobotInfo::set_agv_hydraulic_variables(std::string &temp,
                                               std::string &fill_lvl,
                                               std::string &pressure) {

  hydraulic_system_monitor.set_hydraulic_variables(temp, fill_lvl, pressure);
}

void AGVRobotInfo::publish_data() {

  robotinfo_msgs::RobotInfo10Fields msg_to_pub;
  msg_to_pub.data_field_01 = "robot_description: " + robot_description;
  msg_to_pub.data_field_02 = "serial_number: " + serial_number;
  msg_to_pub.data_field_03 = "ip_address: " + ip_address;
  msg_to_pub.data_field_04 = "firmware_version: " + firmware_version;
  msg_to_pub.data_field_05 =
      "maximum_payload: " + std::to_string(maximum_payload) + " Kg";

  msg_to_pub.data_field_06 =
      "hydraulic_oil_temperature: " +
      hydraulic_system_monitor.get_hydraulic_oil_temperature();
  msg_to_pub.data_field_07 =
      "hydraulic_oil_tank_fill_level: " +
      hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level();
  msg_to_pub.data_field_08 =
      "hydraulic_oil_pressure: " +
      hydraulic_system_monitor.get_hydraulic_oil_pressure();

  info_publisher.publish(msg_to_pub);
}