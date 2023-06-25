# ROS_cartpole_simulation

This is an implementation of an inverted pendulum dynamics in ROS
Please ensure that you have ROS noetic and Gazebo 11 installed before using


In a catkin_ws create a src directory and clone this repo into it
<<<<<<< HEAD
cd ~/catkin_ws and use  roslaunch cartpole_urdf spawn_cartpole.launch to launch
=======
`cd ~/catkin_ws ` and use ` roslaunch cartpole_urdf spawn_cartpole.launch ` to launch
>>>>>>> 7df1b12446378a83cd9ffee83d35de7740f291f4
simulaiton


In order to visualize the model in RVIZ use the following command
<<<<<<< HEAD
roslaunch cartpole_urdf cartpole.launch model:='$(find cartpole_urdf)/urdf/cartpole.urdf'
=======
`roslaunch cartpole_urdf cartpole.launch model:='$(find cartpole_urdf)/urdf/cartpole.urdf'`
>>>>>>> 7df1b12446378a83cd9ffee83d35de7740f291f4
