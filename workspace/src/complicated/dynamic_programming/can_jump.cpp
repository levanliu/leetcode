#include <algorithm>
#include <vector>
namespace ns_complicated_dynamic_programming_can_jump {

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxStep = nums[0];
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (maxStep >= static_cast<int>(i))
                maxStep = std::max(maxStep, static_cast<int>(i) + nums[i]);
        }
        return maxStep >= static_cast<int>(nums.size()) - 1;
    }
};
}  // namespace ns_complicated_dynamic_programming_can_jump
