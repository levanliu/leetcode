#include<iostream>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums){
        int maxStep = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(maxStep >= i) maxStep = max(maxStep,i+nums[i]);
        }
        return maxStep >= nums.size()-1;
    }
};