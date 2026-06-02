#include <iostream>
using namespace std;

class Solution {
public:
    map<int,int> m;
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for(int i=1;i<nums.size()-1;i++){
            if(res == nums[i])
                count++;
            else{
                count--;
                if(count == 0){
                    res = nums[i+1];
                }
            }
        }
        return res;
    }
};