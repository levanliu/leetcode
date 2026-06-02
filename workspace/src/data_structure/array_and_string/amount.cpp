// acwing 5276 — Count integers in [1,n] divisible by 2 but not by 3.
namespace ns_data_structure_array_and_string_amount {

class Solution {
public:
    static int solve(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0 && i % 3 != 0) {
                ++cnt;
            }
        }
        return cnt;
    }
};

}  // namespace ns_data_structure_array_and_string_amount
