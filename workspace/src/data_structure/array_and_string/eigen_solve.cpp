// Eigen eigenvalue solver demo (requires Eigen3 library).
// Build with: g++ -I/path/to/eigen eigen_solve.cpp

namespace ns_data_structure_array_and_string_eigen_solve {

class Solution {
public:
    // See implementation below — requires Eigen3 headers at build time.
    // When Eigen is available, computes eigenvalues of the given 3x3 matrix.
#ifdef EIGEN_WORLD_VERSION
    static void printEigenvalues() {
        Eigen::Matrix3d matrix;
        matrix << 1, 2, 3, 4, 5, 6, 7, 8, 9;
        Eigen::EigenSolver<Eigen::Matrix3d> solver(matrix);
        Eigen::Vector3cd eigenvalues = solver.eigenvalues();
        for (int i = 0; i < 3; ++i) {
            (void)eigenvalues(i);  // use result
        }
    }
#endif
};

}  // namespace ns_data_structure_array_and_string_eigen_solve
