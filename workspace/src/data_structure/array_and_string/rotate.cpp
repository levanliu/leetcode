#include <algorithm>
#include <vector>
// 旋转数组
namespace ns_data_structure_array_and_string_rotate {

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
}  // namespace ns_data_structure_array_and_string_rotate
