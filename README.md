# ROS_cartpole_simulation

This is an implementation of an inverted pendulum dynamics in ROS
Please ensure that you have ROS noetic and Gazebo 11 installed before using


In a catkin_ws create a src directory and clone this repo into it
`cd ~/catkin_ws` and use  `roslaunch cartpole_urdf spawn_cartpole.launch` to launch 
simulaiton

To launch LQR controller use `roslaunch cp_controller my_robot_control.launch`

In order to visualize the model in RVIZ use the following command
`roslaunch cartpole_urdf cartpole.launch model:='$(find cartpole_urdf)/urdf/cartpole.urdf'`

Dependencies: QuadProg++
