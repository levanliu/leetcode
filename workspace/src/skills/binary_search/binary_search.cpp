#pragma once
#include <vector>

namespace ns_skills_binary_search {

class Solution {
public:
    // Returns index of target, -1 if not found
    int search(const std::vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    // First position >= target (lower_bound)
    int lowerBound(const std::vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    // First position > target (upper_bound)
    int upperBound(const std::vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

}  // namespace ns_skills_binary_search
