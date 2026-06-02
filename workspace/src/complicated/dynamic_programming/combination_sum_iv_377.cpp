// LeetCode 377 - Combination Sum IV
// Difficulty: Medium | Category: Dynamic Programming
// https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <unordered_map>
#include <vector>
namespace ns_complicated_dynamic_programming_377_combination_sum_iv {


class Solution {
  std::unordered_map<int, int> memo;
  int dfs(std::vector<int>& nums, int target) {
    if (memo.count(target)) {
      return memo[target];
    }
    if (target == 0) {
      return 1;
    }
    int count = 0;
    for (auto num : nums) {
      if (num <= target) {
        count += dfs(nums, target - num);
      }
    }
    memo[target] = count;
    return count;
  }

  int combinationSum4(std::vector<int>& nums, int target) {
    return dfs(nums, target);
  }
};

int main() {}

} // namespace ns_complicated_dynamic_programming_377_combination_sum_iv
