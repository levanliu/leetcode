// LeetCode 137 - Single Number II
// Difficulty: Medium | Category: Bit Manipulation
// https://leetcode.com/problems/single-number-ii/
namespace ns_skills_bit_manipulation_137_single_number_ii {


class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (int num : nums)
            {
                total += ((num >> i) & 1);
                if (total % 3)
                {
                    ans |= (1 << i);
                }
            }
        }
    }
};
// @lc code=end

} // namespace ns_skills_bit_manipulation_137_single_number_ii
