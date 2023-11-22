#include<iostream>
using namespace std;
class Solution
{
public:
    void moveZeros(vector<int>& nums){
        if(nums.size()<=1) return;
        int index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                nums[index++] = nums[i];
        }
        while(index<nums.size())
            nums[index++] = 0;
    }
};