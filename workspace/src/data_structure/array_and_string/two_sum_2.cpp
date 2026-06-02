//
// Created by le on 25/11/2022.
//

#include <unordered_map>
#include <vector>
namespace ns_array_two_sum_stub {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

}  // namespace ns_array_two_sum_stub
