#include"../include/cp_controller/FSM_data.h"
// #include"cp_controller/FSM_data.h"
#include <iostream>


FSM_data::FSM_data()
{
    cart_position = 0;
    cart_velocity = 0;
    pole_angle = 0;
    pole_velocity = 0;
    lqr_control_input = 0;


    cart_position_error = 0;
    cart_velocity_error = 0;
    pole_angle_error = 0;
    pole_velocity_error = 0;
}

FSM_data::~FSM_data()
{
}


void FSM_data::set_system_state(double cart_position, double cart_velocity, double pole_angle, double pole_velocity)
{
    this->cart_position = cart_position;
    this->cart_velocity = cart_velocity;
    this->pole_angle = pole_angle;
    this->pole_velocity = pole_velocity;
    std::cout << "Current cart position: " << cart_position << "m"      << std::endl;
    std::cout << "Current cart velocity: " << cart_velocity << "m/s"    << std::endl;
    std::cout << "Current pole angle: "    << pole_angle    << "rad"    << std::endl;
    std::cout << "Current pole velocity: " << pole_velocity << "rad/s"  << std::endl;
    //Written out for clarity but can be done in one line
    system_state << cart_position, -pole_angle, cart_velocity, -pole_velocity;

}


void FSM_data::send_command(){
    Eigen::Vector4d lqr_gain;
    lqr_gain <<  -31.6228,  458.3668,  -46.9795,  139.9573;

    lqr_control_input = -lqr_gain.transpose() * system_state;
    std::cout << "LQR control input: " << lqr_control_input << std::endl;
}


double FSM_data::set_command(){
        return lqr_control_input;
    };
