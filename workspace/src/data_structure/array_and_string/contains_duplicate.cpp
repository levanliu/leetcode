#include <algorithm>
#include <vector>
namespace ns_data_structure_array_and_string_contains_duplicate {

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (std::unique(nums.begin(), nums.end()) != nums.end()) {
            return true;
        }
        return false;
    }
};

}  // namespace ns_data_structure_array_and_string_contains_duplicate
