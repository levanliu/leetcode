#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (unique(nums.begin(), nums.end()) != nums.end())
        {
            return true;
        }
        return false;
    }   
};
