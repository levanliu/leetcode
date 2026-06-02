#include <algorithm>
#include <vector>
// 删除排序数组中的重复项
namespace ns_skills_two_pointers_remove_duplicates {

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
}  // namespace ns_skills_two_pointers_remove_duplicates
