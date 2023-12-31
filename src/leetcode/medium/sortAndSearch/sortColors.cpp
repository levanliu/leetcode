#include<iostream>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int leftIndex = 0;
        int rightIndex = nums.size()-1; 
        for(int i=0;i<=rightIndex;i++)
        {
            if(nums[i] == 0)
            {
                swap(nums[i],nums[leftIndex]);
                leftIndex++;
            }
            if(nums[i] == 2)
            {
                swap(nums[i],nums[rightIndex]);
                rightIndex--;
                i--;
            }
        }
    }
};