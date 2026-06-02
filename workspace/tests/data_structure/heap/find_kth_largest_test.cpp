#include "workspace/src/data_structure/heap/find_kth_largest.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("findKthLargest", "[data_structure][heap][find_kth_largest]") {
    using namespace ns_data_structure_heap_find_kth_largest;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {3, 2, 1, 5, 6, 4};
        REQUIRE(sol.findKthLargest(nums, 2) == 5);
    }
    SECTION("another") {
        std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        REQUIRE(sol.findKthLargest(nums, 4) == 4);
    }
}
