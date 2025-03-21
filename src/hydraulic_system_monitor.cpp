#include "robot_info/hydraulic_system_monitor.h"

HydraulicSystemMonitor::HydraulicSystemMonitor(std::string temp,
                                               std::string fill_lvl,
                                               std::string pressure)
    : hydraulic_oil_temperature(temp), hydraulic_oil_tank_fill_level(fill_lvl),
      hydraulic_oil_pressure(pressure) {}

void HydraulicSystemMonitor::set_hydraulic_variables(std::string &temp,
                                                     std::string &fill_lvl,
                                                     std::string &pressure) {
  hydraulic_oil_temperature = temp;
  hydraulic_oil_tank_fill_level = fill_lvl;
  hydraulic_oil_pressure = pressure;
}

const std::string &
HydraulicSystemMonitor::get_hydraulic_oil_temperature() const {
  return hydraulic_oil_temperature;
}

const std::string &
HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() const {
  return hydraulic_oil_tank_fill_level;
}

const std::string &HydraulicSystemMonitor::get_hydraulic_oil_pressure() const {
  return hydraulic_oil_pressure;
}