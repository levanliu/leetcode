#include <vector>
namespace ns_skills_two_pointers_move_zeros {

class Solution {
public:
    void moveZeros(std::vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }
        while (index < nums.size())
            nums[index++] = 0;
    }
};
}  // namespace ns_skills_two_pointers_move_zeros
