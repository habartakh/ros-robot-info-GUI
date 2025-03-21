#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"

class AGVRobotInfo : public RobotInfo {

public:
  AGVRobotInfo();
  AGVRobotInfo(ros::NodeHandle *, std::string, std::string, std::string,
               std::string, int, HydraulicSystemMonitor &);
  void set_agv_general_variables(std::string &, std::string &, std::string &,
                                 std::string &, int);
  void set_agv_hydraulic_variables(std::string &, std::string &, std::string &);
  void publish_data() override;

protected:
  int maximum_payload;
  HydraulicSystemMonitor hydraulic_system_monitor;
};

#endif