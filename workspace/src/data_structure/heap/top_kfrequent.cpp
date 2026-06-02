#include <map>
#include <queue>
#include <utility>
#include <vector>
namespace ns_data_structure_heap_top_kfrequent {

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }

        auto cmp = [](std::pair<int, int> x, std::pair<int, int> y) {
            return x.second < y.second;
        };

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(cmp)>
            pq(cmp);
        for (auto& kv : m) {
            pq.push(kv);
        }

        std::vector<int> res(k);
        for (int i = 0; i < k; i++) {
            auto kv = pq.top();
            pq.pop();
            res[i] = kv.first;
        }

        return res;
    }
};
}  // namespace ns_data_structure_heap_top_kfrequent
