#pragma once
#include <iostream>
#include <Eigen/Dense>
#include "../../QuadProgpp/src/QuadProg++.hh"
#include "QP_controller.h"


class FSM_data
{
    public:
    FSM_data();
    ~FSM_data();

    void set_system_state(double cart_position, double cart_velocity, double pole_angle, double pole_velocity);
    Eigen::Vector4d get_system_state(){return system_state;};
    void calc_command();
    double get_command();

    QP_control qp_control;

    private:
    double cart_position;
    double cart_velocity;
    double pole_angle;
    double pole_velocity;
    int controller_type;

    Eigen::Vector4d system_state;
    Eigen::Vector4d lqr_gain;


    double control_input;

};