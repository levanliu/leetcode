#include "workspace/src/data_structure/array_and_string/four_sum_count.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("fourSumCount", "[data_structure][array_and_string][four_sum_count]") {
    using namespace ns_data_structure_array_and_string_four_sum_count;
    Solution sol;
    SECTION("basic") {
        std::vector<int> n1={1,2}, n2={-2,-1}, n3={-1,2}, n4={0,2};
        REQUIRE(sol.fourSumCount(n1, n2, n3, n4) == 2);
    }
    SECTION("all zeros") {
        std::vector<int> n1={0}, n2={0}, n3={0}, n4={0};
        REQUIRE(sol.fourSumCount(n1, n2, n3, n4) == 1);
    }
}
