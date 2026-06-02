#include <algorithm>
#include <vector>
namespace ns_data_structure_array_and_string_intersect {

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int m = nums1.size();
        int n = nums2.size();

        int p1 = 0, p2 = 0;
        std::vector<int> res;
        while (p1 < m && p2 < n) {
            if (nums1[p1] < nums2[p2]) {
                p1++;
            } else if (nums1[p1] > nums2[p2]) {
                p2++;
            } else {
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return res;
    }
};
}  // namespace ns_data_structure_array_and_string_intersect
