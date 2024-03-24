#include <iostream>
//#include <Eigen/Eigenvalues>
#include "C:/Program Files (x86)/Eigen3/include/eigen3/Eigen/Eigenvalues"

int main() {
   // Create a 3x3 matrix
   Eigen::Matrix3d matrix;
   matrix << 1, 2, 3,
             4, 5, 6,
             7, 8, 9;

   // Calculate the eigenvalues
   Eigen::EigenSolver<Eigen::Matrix3d> eigenSolver(matrix);
   Eigen::Vector3cd eigenvalues = eigenSolver.eigenvalues();

   // Print the eigenvalues
   for (int i = 0; i < 3; i++) {
      std::cout << "Eigenvalue #" << i + 1 << ": " << eigenvalues(i).real()
                << " + " << eigenvalues(i).imag() << "i" << std::endl;
   }

   return 0;
}
