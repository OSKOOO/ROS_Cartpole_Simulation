#include "controller_manager/controller_manager.h"
#include "cp_hardware_interface/cp_hardware_interface.hpp"
#include "ros/ros.h"
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float64.h>
#include"/home/obot/catkin_ws/src/cp_controller/include/cp_controller/FSM_data.h"

ros::Publisher effort_pub;
cp_HardwareInterface cphi;
FSM_data cp_data;
double control_input;
void counterCallback(const sensor_msgs::JointState::ConstPtr& msg) // Define a function called 'callback' that receives a                                                                // parameter named 'msg' 
{
  cp_data.set_system_state(msg->position[0], msg->velocity[0], msg->position[1], msg->velocity[1]);

  cp_data.send_command();
  control_input = cp_data.set_command();
  std_msgs::Float64 effort_msg;
  effort_msg.data = control_input;
  effort_pub.publish(effort_msg);
}

int main(int argc, char** argv) {

    ros::init(argc, argv, "cp_hardware_interface"); // Initiate a Node called 'topic_subscriber'
    ros::NodeHandle nh;
    
    ros::Subscriber sub1 = nh.subscribe("/cart_pole/joint_states", 1000, counterCallback);
    effort_pub = nh.advertise<std_msgs::Float64>("/cart_pole/cart_joint_effort_controller/command", 1);                                                             

    // ros::Subscriber sub2 = nh.subscribe("/joint_states", 1000, counterCallback);                                                                           

    ros::spin(); // Create a loop that will keep the program in execution
    
    return 0;
}









































// int main(int argc, char** argv)
// {
//   ros::init(argc, argv, "cp_hardware_interface");

//   // NOTE: We run the ROS loop in a separate thread as external calls such
//   // as service callbacks to load controllers can block the (main) control loop
//   ros::AsyncSpinner spinner(3);
//   spinner.start();

//   ros::NodeHandle root_nh;
//   ros::NodeHandle robot_nh("~");

//   cp_hardware_interface::cp_HardwareInterface cp_hardware_interface;
//   controller_manager::ControllerManager controller_manager(&cp_hardware_interface, root_nh);


//   // Set up timers
//   ros::Time timestamp;
//   ros::Duration period;
//   auto stopwatch_last = std::chrono::steady_clock::now();
//   auto stopwatch_now = stopwatch_last;

//   cp_hardware_interface.init(root_nh, robot_nh);

//   ros::Rate loop_rate(100);

//   while(ros::ok())
//   {
//     // Receive current state from robot
//     if (!cp_hardware_interface.read(timestamp, period)) {
//       ROS_FATAL_NAMED("cp_hardware_interface",
//                       "Failed to read state from robot. Shutting down!");
//       ros::shutdown();
//     }

//     // Get current time and elapsed time since last read
//     timestamp = ros::Time::now();
//     stopwatch_now = std::chrono::steady_clock::now();
//     period.fromSec(std::chrono::duration_cast<std::chrono::duration<double>>(
//       stopwatch_now - stopwatch_last).count());
//     stopwatch_last = stopwatch_now;

//     hardware_interface::JointHandle cj_handle;

//     // Update the controllers
//     controller_manager.update(timestamp, period);

//     // Send new setpoint to robot
//     cp_hardware_interface.write(timestamp, period);

//     loop_rate.sleep();
//   }

//   spinner.stop();
//   ROS_INFO_NAMED("cp_hardware_interface", "Shutting down.");

//   return 0;
// }
