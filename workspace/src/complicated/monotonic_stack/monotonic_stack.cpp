#pragma once
#include <algorithm>
#include <stack>
#include <vector>

namespace ns_complicated_monotonic_stack {

class Solution {
public:
    // For each element, index of nearest smaller element to the left (-1 if none)
    std::vector<int> prevSmaller(const std::vector<int>& nums) {
        std::vector<int> res(nums.size(), -1);
        std::stack<int> stk;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                res[i] = stk.top();
            }
            stk.push(i);
        }
        return res;
    }

    // For each element, index of nearest greater element to the right (-1 if none)
    std::vector<int> nextGreater(const std::vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                res[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }

    // Largest rectangle in histogram
    int largestRectangle(const std::vector<int>& heights) {
        std::stack<int> stk;
        int maxArea = 0;
        int n = (int)heights.size();
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!stk.empty() && heights[stk.top()] > h) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
};

}  // namespace ns_complicated_monotonic_stack
