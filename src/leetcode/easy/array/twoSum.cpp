#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!m.count(nums[i]))
            {
                m[target - nums[i]] = i;
            }
            else
            {
                res.push_back(m[nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};