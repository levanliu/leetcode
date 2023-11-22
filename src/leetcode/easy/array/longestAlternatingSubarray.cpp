#include <bits/stdc++.h>

#include <cstring>
using namespace std;

/*
        * 给你一个下标从 0 开始的整数数组 nums 和一个整数 threshold 。

请你从 nums 的子数组中找出以下标 l 开头、下标 r 结尾 (0 <= l <= r < nums.length)
且满足以下条件的 最长子数组 ：

nums[l] % 2 == 0
对于范围 [l, r - 1] 内的所有下标 i ，nums[i] % 2 != nums[i + 1] % 2
对于范围 [l, r] 内的所有下标 i ，nums[i] <= threshold
以整数形式返回满足题目要求的最长子数组的长度。

注意：子数组 是数组中的一个连续非空元素序列。
        */

class Solution {
 public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    /*
     * 考虑动态规划
     * f(l,r+1) = f(l,r)  nums[r]%2 == nums[r+1]%2 || nums[r+1] > threshold
     * or
     * f(l,r+1) = f(l,r) + 1   nums[r]%2 != nums[r+1]%2 && nums[r+1] <=
     * threshold
     *
     * l [0,r-2]
     * r [0,r-2]
     */
    int res = 0, dp = 0, n = nums.size();
    for (int l = n - 1; l >= 0; l--) {
      if (nums[l] > threshold) {
        dp = 0;
      } else if (l == n - 1 || nums[l] % 2 != nums[l + 1] % 2) {
        dp++;
      } else {
        dp = 1;
      }
      if (nums[l] % 2 == 0) {
        res = max(res, dp);
      }
    }
    return res;
  }
};


/*
class Solution {
public:
    bool isSatisfied(vector<int> &nums, int l, int r, int threshold) {
        if (nums[l] % 2 != 0) {
            return false;
        }
        for (int i = l; i <= r; i++) {
            if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2)) {
                return false;
            }
        }
        return true;
    }

    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, n = nums.size();
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isSatisfied(nums, l, r, threshold)) {
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
*/
};
