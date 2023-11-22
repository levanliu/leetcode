#include<iostream>
using namespace std;

// 删除排序数组中的重复项
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};