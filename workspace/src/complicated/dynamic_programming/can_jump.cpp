#include <algorithm>
#include <vector>
namespace ns_complicated_dynamic_programming_can_jump {

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxStep = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (maxStep >= i)
                maxStep = std::max(maxStep, i + nums[i]);
        }
        return maxStep >= nums.size() - 1;
    }
};
}  // namespace ns_complicated_dynamic_programming_can_jump
