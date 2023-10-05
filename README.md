# ROS_cartpole_simulation
![ezgif com-video-to-gif(6)](https://github.com/OSKOOO/ROS_Cartpole_Simulation/assets/111469977/54fb22ec-a3b3-4bfe-9d65-078153152cf1)


This is an implementation of an inverted pendulum dynamics in ROS
Please ensure that you have ROS Noetic and Gazebo 11 installed before using


In a catkin_ws create a src directory and clone this repo into it
`cd ~/catkin_ws` and use  `roslaunch cartpole_urdf spawn_cartpole.launch` to launch 
simulaiton

To launch LQR controller use `roslaunch cp_controller my_robot_control.launch`

In order to switch to QP controller (enforces an input constraint), go to FSM_data.cpp and switch controller type to 1. 

In order to visualize the model in RVIZ use the following command
`roslaunch cartpole_urdf cartpole.launch model:='$(find cartpole_urdf)/urdf/cartpole.urdf'`

Dependencies: QuadProg++
