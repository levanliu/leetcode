#include <queue>
#include <vector>
namespace ns_data_structure_heap_find_kth_largest {

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq;

        for (auto num : nums) {
            pq.push(num);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
}  // namespace ns_data_structure_heap_find_kth_largest
