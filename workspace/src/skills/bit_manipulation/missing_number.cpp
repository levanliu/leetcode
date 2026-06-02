#include<iostream>
using namespace std;
namespace ns_skills_bit_manipulation_missing_number {

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (0+nums.size())*(nums.size()+1)/2;
        for(int num:nums){
            sum -= num;
        }
        return sum;
    }
};
} // namespace ns_skills_bit_manipulation_missing_number
