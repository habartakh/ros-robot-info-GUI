#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/rate.h"
#include <ros/ros.h>

class RobotInfo {
public:
  RobotInfo();
  RobotInfo(ros::NodeHandle *, std::string, std::string, std::string,
            std::string);
  virtual void publish_data();

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  ros::NodeHandle *nh;
  ros::Publisher info_publisher;
};

#endif