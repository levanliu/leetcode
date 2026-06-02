// Two-pointer: find i,j from two sorted arrays such that a[i]+b[j]==x.
#include <utility>
#include <vector>

namespace ns_data_structure_array_and_string_two_sum_sorted_pairs {

class Solution {
public:
    // Returns {i, j} such that a[i]+b[j]==x, or {-1,-1} if not found.
    // Precondition: a is sorted ascending, b is sorted ascending.
    static std::pair<int, int> findPair(const std::vector<int>& a,
                                        const std::vector<int>& b, int x) {
        int i = 0;
        int j = static_cast<int>(b.size()) - 1;
        while (i < static_cast<int>(a.size()) && j >= 0) {
            int s = a[i] + b[j];
            if (s == x) {
                return {i, j};
            }
            if (s > x) {
                --j;
            } else {
                ++i;
            }
        }
        return {-1, -1};
    }
};

}  // namespace ns_data_structure_array_and_string_two_sum_sorted_pairs
