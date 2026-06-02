// Data statistics: min, max, average from a vector of integers.
#include <climits>
#include <vector>

namespace ns_data_structure_array_and_string_data_statistics {

struct Stats {
    int minVal = 0;
    int maxVal = 0;
    double avg = 0.0;
};

class Solution {
public:
    static Stats computeStats(const std::vector<int>& data) {
        if (data.empty()) {
            return {};
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        long long sum = 0;
        for (int x : data) {
            if (x < minVal) {
                minVal = x;
            }
            if (x > maxVal) {
                maxVal = x;
            }
            sum += x;
        }
        return {minVal, maxVal,
                static_cast<double>(sum) / static_cast<double>(data.size())};
    }
};

}  // namespace ns_data_structure_array_and_string_data_statistics
