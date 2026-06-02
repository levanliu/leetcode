#include "workspace/src/search/interval/merge.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("mergeSortedArrays", "[search][interval][merge]") {
    using namespace ns_search_interval_merge;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums1 = {1,2,3,0,0,0};
        std::vector<int> nums2 = {2,5,6};
        sol.merge(nums1, 3, nums2, 3);
        REQUIRE((nums1 == std::vector<int>{1,2,2,3,5,6}));
    }
    SECTION("nums2 into empty nums1") {
        std::vector<int> nums1 = {0};
        std::vector<int> nums2 = {1};
        sol.merge(nums1, 0, nums2, 1);
        REQUIRE((nums1 == std::vector<int>{1}));
    }
}
