#include<iostream>
using namespace std;
// 旋转数组
namespace ns_data_structure_array_and_string_rotate {

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
} // namespace ns_data_structure_array_and_string_rotate
