#include <vector>
namespace ns_skills_binary_search_search_range {

class Solution {
public:
    int binSearch1(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }

    int binSearch2(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> res(2, -1);
        if (nums.size() == 0) {
            return res;
        }
        res[0] = binSearch1(nums, target);
        res[1] = binSearch2(nums, target);
        return res;
    }
};
}  // namespace ns_skills_binary_search_search_range
