#include <iostream>
#include "Eigen/Eigenvalues"
//root: cmake -B build && cd build && cmake --build . --target install
//g++ -I"C:/Program Files (x86)/Eigen3/include/eigen3" eigenSolve.cpp -o eigenSolve.exe
int main() {
   // Create a 3x3 matrix
   Eigen::Matrix3d matrix;
   matrix << 1, 2, 3,
             4, 5, 6,
             7, 8, 9;

   // Calculate the eigenvalues and eigenvectors
   Eigen::EigenSolver<Eigen::Matrix3d> eigenSolver(matrix);
   Eigen::Vector3cd eigenvalues = eigenSolver.eigenvalues();
   Eigen::Matrix3cd eigenvectors = eigenSolver.eigenvectors();

   // Print the eigenvalues and eigenvectors
   std::cout << "Eigenvalues:" << std::endl;
   for (int i = 0; i < 3; i++) {
      std::cout << "Eigenvalue #" << i + 1 << ": " << eigenvalues(i).real()
                << " + " << eigenvalues(i).imag() << "i" << std::endl;
   }

   std::cout << "\nEigenvectors:" << std::endl;
   for (int i = 0; i < 3; i++) {
      std::cout << "Eigenvector #" << i + 1 << ":" << std::endl;
      std::cout << eigenvectors.col(i) << std::endl << std::endl;
   }

   return 0;
}


// Eigenvalue #1: 16.1168 + 0i
// Eigenvalue #2: -1.11684 + 0i
// Eigenvalue #3: 1.6795e-15 + 0i

// Eigenvectors:
// Eigenvector #1:
// (0.231971,0)
// (0.525322,0)
// (0.818673,0)

// Eigenvector #2:
//   (0.78583,0)
// (0.0867513,0)
// (-0.612328,0)

// Eigenvector #3:
//  (0.408248,0)
// (-0.816497,0)
//  (0.408248,0)