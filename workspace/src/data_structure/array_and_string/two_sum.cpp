#pragma once
#include <vector>
#include <unordered_map>

namespace ns_data_structure_array_and_string_two_sum {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

}  // namespace ns_data_structure_array_and_string_two_sum
