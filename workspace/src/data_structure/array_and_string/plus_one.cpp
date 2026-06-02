#include<iostream>
using namespace std;
namespace ns_data_structure_array_and_string_plus_one {

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        vector<int> res;
        res.push_back(1);
        for (int i = 0; i < digits.size(); i++)
        {
            res.push_back(0);
        }
        return res;
    }
};
} // namespace ns_data_structure_array_and_string_plus_one
