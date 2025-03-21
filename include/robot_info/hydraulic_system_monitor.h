#ifndef HYDRAULIC_SYSTEM_MONITOR_H
#define HYDRAULIC_SYSTEM_MONITOR_H

#include <ros/ros.h>
#include <string>

class HydraulicSystemMonitor {

public:
  HydraulicSystemMonitor() = default;
  HydraulicSystemMonitor(std::string, std::string, std::string);
  void set_hydraulic_variables(std::string &, std::string &, std::string &);
  const std::string &get_hydraulic_oil_temperature() const;
  const std::string &get_hydraulic_oil_tank_fill_level() const;
  const std::string &get_hydraulic_oil_pressure() const;

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};

#endif