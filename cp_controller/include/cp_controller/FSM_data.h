#pragma once
#include <iostream>
#include <Eigen/Dense>


class FSM_data
{
    public:
    FSM_data();
    ~FSM_data();

    void set_system_state(double cart_position, double cart_velocity, double pole_angle, double pole_velocity);
    void send_command();
    double set_command();

    private:
    double cart_position;
    double cart_velocity;
    double pole_angle;
    double pole_velocity;

    double cart_position_error;
    double cart_velocity_error;
    double pole_angle_error;
    double pole_velocity_error;

    Eigen::Vector4d system_state;

    double lqr_control_input;

};