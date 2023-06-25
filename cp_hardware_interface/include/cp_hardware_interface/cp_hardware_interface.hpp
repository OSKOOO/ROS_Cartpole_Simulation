#ifndef RRBOT_HARDWARE_INTERFACE__RRBOT_HARDWARE_INTERFACE_HPP_
#define RRBOT_HARDWARE_INTERFACE__RRBOT_HARDWARE_INTERFACE_HPP_

#include <string>
#include <vector>

#include <controller_interface/controller.h>
#include "hardware_interface/joint_command_interface.h"
#include "hardware_interface/joint_state_interface.h"
#include "hardware_interface/robot_hw.h"

// namespace cp_hardware_interface
// {
class cp_HardwareInterface : public hardware_interface::RobotHW
{
public:
  cp_HardwareInterface();
  ~cp_HardwareInterface();  
  void init();
  void set_position_state(std::vector<double> position_command);
// //The init() function will be used to create and register the joint interfaces. 
//   bool init(ros::NodeHandle & root_nh, ros::NodeHandle & robot_hw_nh);

// // The read() function will be used to read the joint states from the hardware.
//   bool read(const ros::Time time, const ros::Duration period);

// // The write() function will be used to write the joint commands to the hardware.
//   bool write(const ros::Time time, const ros::Duration period);

private:
  // hardware_interface::JointStateInterface joint_state_interface_;
  // hardware_interface::PositionJointInterface position_command_interface_;
  // hardware_interface::JointStateHandle cart_joint;
  std::vector<double> hw_position_commands_;
  std::vector<double> hw_position_states_;
  std::vector<double> hw_velocity_states_;
  std::vector<double> hw_effort_states_;

  std::vector<std::string> joint_names_;
};

// }  // namespace rrbot_hardware_interface

#endif  // RRBOT_HARDWARE_INTERFACE__RRBOT_HARDWARE_INTERFACE_HPP_
