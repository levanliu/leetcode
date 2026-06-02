#include <algorithm>
#include <vector>
namespace ns_data_structure_array_and_string_shuffle_array {

class Solution {
private:
    std::vector<int> res;

public:
    Solution(std::vector<int>& nums) { res = nums; }

    std::vector<int> reset() { return res; }

    std::vector<int> std::shuffle() {
        int n = res.size();
        std::vector<int> temp = res;
        for (int i = n; i; i--) {
            int pos = rand() % i;
            std::swap(temp[pos], temp[i - 1]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * std::vector<int> param_1 = obj->reset();
 * std::vector<int> param_2 = obj->std::shuffle();
 */
}  // namespace ns_data_structure_array_and_string_shuffle_array
