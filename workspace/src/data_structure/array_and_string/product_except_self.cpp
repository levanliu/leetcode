#include <iostream>
using namespace std;
namespace ns_data_structure_array_and_string_product_except_self {


class Solution
{
public:
    vector<int> productExcepSelf(vector<int> &nums)
    {
        int n = nums.size();
        int L = 1, R = 1;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            res[i] *= L;
            res[n - i - 1] *= R;
            L *= nums[i];
            R *= nums[n - i - 1];
        }
        return res;
    }
};
} // namespace ns_data_structure_array_and_string_product_except_self
