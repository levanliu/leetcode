#include <map>
#include <vector>
namespace ns_complicated_sort_majority_element {

class Solution {
public:
    std::map<int, int> m;
    int majorityElement(std::vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for (std::size_t i = 1; i < nums.size() - 1; i++) {
            if (res == nums[i])
                count++;
            else {
                count--;
                if (count == 0) {
                    res = nums[i + 1];
                }
            }
        }
        return res;
    }
};
}  // namespace ns_complicated_sort_majority_element
