#include <iostream>
#include <Eigen/Dense>
#include "../../QuadProgpp/src/QuadProg++.hh"



class QP_control
{
    public:
    QP_control();
    ~QP_control();

    double solve_QP();
    void set_system_state(Eigen::VectorXd system_state){this->system_state = system_state;};

    private:

    Eigen::VectorXd system_state;
    Eigen::Vector4d optimal_gain;

    //QuadProg++ Matrices
    quadprogpp::Matrix<double> H;   //Hessian matrix
    quadprogpp::Vector<double> g;   //Gradient vector
    quadprogpp::Matrix<double> A;   //Inequality Constraint matrix
    quadprogpp::Vector<double> b;   //Inequality Constraint vector
    quadprogpp::Matrix<double> CE;  //Equality Constraint matrix
    quadprogpp::Vector<double> ce0; //Equality Constraint vector
    quadprogpp::Vector<double> x;   //Solution vector

    //Optimal Control Input
    double optimal_control_input = 0;   
    double qp_input = 0;               //QP solution

    
};