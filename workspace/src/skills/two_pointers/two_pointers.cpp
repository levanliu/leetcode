#pragma once
#include <vector>
#include <utility>

namespace ns_skills_two_pointers {

class Solution {
public:
    // Find two indices in sorted array that sum to target
    std::pair<int,int> twoSumSorted(const std::vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) return {l, r};
            else if (sum < target) l++;
            else r--;
        }
        return {-1, -1};
    }

    // Remove duplicates from sorted array, return new length
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int fast = 1; fast < (int)nums.size(); fast++)
            if (nums[fast] != nums[slow]) nums[++slow] = nums[fast];
        return slow + 1;
    }

    // Move zeros to end, maintain relative order
    void moveZeros(std::vector<int>& nums) {
        int pos = 0;
        for (int x : nums) if (x != 0) nums[pos++] = x;
        while (pos < (int)nums.size()) nums[pos++] = 0;
    }
};

}  // namespace ns_skills_two_pointers
