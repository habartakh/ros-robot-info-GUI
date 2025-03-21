#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"

class AGVRobotInfo : public RobotInfo {

public:
  AGVRobotInfo();
  AGVRobotInfo(ros::NodeHandle *, std::string, std::string, std::string,
               std::string, int);
  void publish_data() override;

protected:
  int maximum_payload;
};

#endif