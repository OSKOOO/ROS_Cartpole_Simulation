// #include <Eigen/Dense>
// #include <iostream>


// // #include <ct/core/core.h>
// // #include <ct/optcon/optcon.h>


// Eigen::MatrixXd solveCARE(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R) {
//     int n = A.rows();
//     assert(A.cols() == n && B.rows() == n && Q.rows() == n && Q.cols() == n && R.rows() == B.cols() && R.cols() == B.cols());

//     Eigen::MatrixXd M(2 * n, 2 * n);
//     M << A, -B * R.inverse() * B.transpose(),
//          -Q, -A.transpose();

//     Eigen::ComplexEigenSolver<Eigen::MatrixXd> ces;
//     ces.compute(M);

//     Eigen::MatrixXcd Z = ces.eigenvectors();
//     Eigen::MatrixXcd S = Z.topRows(n), T = Z.bottomRows(n);

//     if (S.cols() != S.rows()) {
//         std::cerr << "Matrix S is not square." << std::endl;
//         return Eigen::MatrixXd();
//     }

//     Eigen::MatrixXcd P = T * S.inverse();

//     // Check if P is approximately a real matrix
//     if ((P - P.real()).norm() < 1e-9) {
//         return P.real();
//     }

//     std::cerr << "No real solution found" << std::endl;
//     return Eigen::MatrixXd();
// }

// Eigen::MatrixXd lqr(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R) {
//     Eigen::MatrixXd P = solveCARE(A, B, Q, R);
//     if (P.size() > 0) { // If P is not empty
//         return R.inverse() * B.transpose() * P;
//     }
//     return Eigen::MatrixXd();
// }

// int main() {
//     // Define the state-space representation of the system
//     Eigen::MatrixXd A(4, 4);
//     A << 1, 1, 0, 1,
//          0, 1, 1, 0,
//          0, 0, 1, 1,
//          0, 0, 0, 1;
    
//     Eigen::MatrixXd B(2, 1);
//     B << 0, 1;
    
//     Eigen::MatrixXd Q(2, 2);
//     Q << 1, 0, 0, 1;
    
//     Eigen::MatrixXd R(1, 1);
//     R << 1;
    
//     // Solve for the optimal gain matrix K
//     Eigen::MatrixXd K = lqr(A, B, Q, R);
    
//     // Output the gain matrix K
//     std::cout << "K = " << std::endl << K << std::endl;
    
//     return 0;
// }
