#include "../include/cp_controller/QP_controller.h"


QP_control::QP_control(){
    //Define the Hessian matrix
    H.resize(1,1);
    H[0][0] = 2.0;

    //Define the gradient vector
    g.resize(1);
    g[0] = -2.0 * optimal_control_input;

    //Define the constraint matrix
    A.resize(1,2);
    A[0][0] =  1.0;
    A[0][1] = -1.0;

    //Define the constraint vector
    b.resize(2);
    b[0] = 300.0;   //Max control input
    b[1] = 300.0;   //Min control input

    //Define the equality constraint matrix
    CE.resize(1,0);

    //Define the equality constraint vector
    ce0.resize(0);

    //Define the solution vector
    x.resize(1);

}

QP_control::~QP_control(){}

double QP_control::solve_QP(){

    //Define optimal gain based on lqr gain calculated in MATLAB    
    optimal_gain <<  -31.6228,  471.9685,  -49.4682,  144.3730;

    // optimal_gain <<  -31.6228,  458.3668,  -46.9795,  139.9573;
    optimal_control_input = -optimal_gain.transpose() * system_state; 
    //Evaluate the gradient vector
    g[0] = -2.0 * optimal_control_input;
    
    //Solve the QP
    qp_input = quadprogpp::solve_quadprog(H, g, CE, ce0, A, b, x);
    return x[0];
}