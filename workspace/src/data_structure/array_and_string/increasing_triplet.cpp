#include<iostream>
using namespace std;
namespace ns_data_structure_array_and_string_increasing_triplet {


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int num : nums) {
            if (num <= small) {
                small = num;
            } else if (num <= mid) {
                mid = num;
            } else {
                return true;
            }
        }
        return false;
    }
};
} // namespace ns_data_structure_array_and_string_increasing_triplet
