#include <vector>
namespace ns_skills_bit_manipulation_single_number {

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int res = 0;
        for (auto num : nums)
            res ^= num;
        return res;
    }
};

}  // namespace ns_skills_bit_manipulation_single_number
