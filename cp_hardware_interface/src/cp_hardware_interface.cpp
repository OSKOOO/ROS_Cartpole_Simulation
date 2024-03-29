#include "cp_hardware_interface/cp_hardware_interface.hpp"

#include <limits>
#include <vector>


// namespace cp_hardware_interface
// {
cp_HardwareInterface::cp_HardwareInterface(){}
cp_HardwareInterface::~cp_HardwareInterface(){}

void cp_HardwareInterface::set_position_state(std::vector<double> position_state)
{
  hw_position_states_ = position_state;
  ROS_INFO("Current state %.5f", hw_position_states_[0]);
}


// }











































// namespace cp_hardware_interface
// {

// bool cp_HardwareInterface::init(ros::NodeHandle & /*root_nh*/, ros::NodeHandle & robot_hw_nh)
// {
//   if (!robot_hw_nh.getParam("joint_names", joint_names_))
//   {
//     ROS_ERROR("Cannot find required parameter 'joint_names' on the parameter server.");
//     throw std::runtime_error("Cannot find required parameter "
//     "'joint_names' on the parameter server.");
//   }

//   size_t num_joints = joint_names_.size();
//   ROS_INFO_NAMED("cp_hardware_interface", "Found %zu joint(s).", num_joints);
  
//   hw_position_states_.resize(num_joints, std::numeric_limits<double>::quiet_NaN());
//   hw_position_commands_.resize(num_joints, std::numeric_limits<double>::quiet_NaN());
//   hw_velocity_states_.resize(num_joints, std::numeric_limits<double>::quiet_NaN());
//   hw_effort_states_.resize(num_joints, std::numeric_limits<double>::quiet_NaN());

//   // Create ros_control interfaces
//   for (size_t i = 0; i < num_joints; ++i)
//   {
//     // Create joint state interface for all joints
//     joint_state_interface_.registerHandle(
//       hardware_interface::JointStateHandle(
//         joint_names_[i], &hw_position_states_[i], &hw_velocity_states_[i], &hw_effort_states_[i]));
    
//     // Create joint position control interface
//     position_command_interface_.registerHandle(
//       hardware_interface::JointHandle(
//         joint_state_interface_.getHandle(joint_names_[i]), &hw_position_commands_[i]));
//   }
  

//   registerInterface(&joint_state_interface_);
//   registerInterface(&position_command_interface_);


//   // stat execution on hardware
//   ROS_INFO_NAMED("cp_hardware_interface", "Starting...");



//   // in this simple example reset state to initial positions
//   for (size_t i = 0; i < num_joints; ++i){
//     hw_position_states_[i] = 0.0;  // INITIAL POSITION is ZERO
//     hw_position_commands_[i] = hw_position_states_[i];
//   }

//   return true;
// }

// bool cp_HardwareInterface::read(const ros::Time time, const ros::Duration period)
// { 
  
//   cart_joint = joint_state_interface_.getHandle(joint_names_[0]);
//   // read robot states from hardware, in this example print only
//   ROS_INFO_NAMED("cp_hardware_interface", "Reading...");
//   hw_position_states_[0] = cart_joint.getPosition();

//   // write command to hardware, in this example do mirror command to states
//   for (size_t i = 0; i < hw_position_states_.size(); ++i) {

//     ROS_INFO_NAMED("cp_hardware_interface",
//                    "Got state %.2f for joint %zu!", hw_position_states_[i] , i);
//   }
//   ROS_INFO_NAMED("cp_hardware_interface", "Current state %.5f", hw_position_states_[0]);

//   return true;
// }

// bool cp_HardwareInterface::write(const ros::Time time, const ros::Duration period)
// {
  
//   // write command to hardware, in this example do mirror command to states
//   for (size_t i = 0; i < hw_position_commands_.size(); ++i) {
//     hw_position_states_[i] = hw_position_states_[i] +
//                              (hw_position_commands_[i] - hw_position_states_[i]) / 100.0;
//   }

//   return true;
// }

// }  // namespace rrbot_hardware_interface
