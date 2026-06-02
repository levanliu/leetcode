#include <algorithm>
#include <vector>
namespace ns_complicated_sort_sort_colors {

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        for (int i = 0; i <= rightIndex; i++) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[leftIndex]);
                leftIndex++;
            }
            if (nums[i] == 2) {
                std::swap(nums[i], nums[rightIndex]);
                rightIndex--;
                i--;
            }
        }
    }
};
}  // namespace ns_complicated_sort_sort_colors
