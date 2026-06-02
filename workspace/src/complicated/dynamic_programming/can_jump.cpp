#include<iostream>
using namespace std;
namespace ns_complicated_dynamic_programming_can_jump {


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
} // namespace ns_complicated_dynamic_programming_can_jump
