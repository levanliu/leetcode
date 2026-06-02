// Floating-point precision: demonstrates that summing 0.1 repeatedly
// does not cleanly reach 10.0 due to IEEE-754 representation errors.
#include <vector>

namespace ns_data_structure_array_and_string_double_precision {

class Solution {
public:
    // Returns the first `steps` values of the sequence 0, 0.1, 0.2, ...
    static std::vector<double> floatSequence(int steps) {
        std::vector<double> result;
        result.reserve(steps);
        double val = 0.0;
        for (int k = 0; k < steps; ++k) {
            result.push_back(val);
            val += 0.1;
        }
        return result;
    }
};

}  // namespace ns_data_structure_array_and_string_double_precision
