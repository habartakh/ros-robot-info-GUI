#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  HydraulicSystemMonitor hydraulic_system_monitor("45C", "100%", "250 bar");
  AGVRobotInfo agv_robot_info(&nh, "Mir100", "567A359", "169.254.5.180",
                              "3.5.8", 100, hydraulic_system_monitor);

  while (ros::ok()) {
    agv_robot_info.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}