#include<iostream>
#include<vector>

using namespace std;
namespace ns_data_structure_array_and_string_contains_duplicate {


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

} // namespace ns_data_structure_array_and_string_contains_duplicate
