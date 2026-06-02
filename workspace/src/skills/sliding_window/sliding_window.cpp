#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <algorithm>

namespace ns_skills_sliding_window {

class Solution {
public:
    // Maximum sum subarray of fixed size k
    int maxSumSubarray(const std::vector<int>& nums, int k) {
        if ((int)nums.size() < k) return 0;
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int maxSum = sum;
        for (int i = k; i < (int)nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }

    // Length of longest substring without repeating characters
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> last;
        int maxLen = 0, start = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (last.count(s[i]) && last[s[i]] >= start)
                start = last[s[i]] + 1;
            last[s[i]] = i;
            maxLen = std::max(maxLen, i - start + 1);
        }
        return maxLen;
    }

    // Maximum value in each sliding window of size k
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::deque<int> dq;
        std::vector<int> result;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

}  // namespace ns_skills_sliding_window
