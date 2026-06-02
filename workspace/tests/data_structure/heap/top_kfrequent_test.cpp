#include "workspace/src/data_structure/heap/top_kfrequent.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("topKFrequent", "[data_structure][heap][top_kfrequent]") {
    using namespace ns_data_structure_heap_top_kfrequent;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 1, 1, 2, 2, 3};
        auto result = sol.topKFrequent(nums, 2);
        REQUIRE(result.size() == 2);
        REQUIRE(std::find(result.begin(), result.end(), 1) != result.end());
        REQUIRE(std::find(result.begin(), result.end(), 2) != result.end());
    }
    SECTION("single") {
        std::vector<int> nums = {1};
        auto result = sol.topKFrequent(nums, 1);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 1);
    }
}
