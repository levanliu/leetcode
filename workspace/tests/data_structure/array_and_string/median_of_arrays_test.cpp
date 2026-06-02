#include "workspace/src/data_structure/array_and_string/median_of_arrays.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("findMedianSortedArrays", "[data_structure][array_and_string][median_arrays]") {
    using namespace ns_array_median_of_arrays;
    Solution sol;
    SECTION("odd total") {
        std::vector<int> n1 = {1, 3}, n2 = {2};
        REQUIRE(sol.findMedianSortedArrays(n1, n2) == 2.0);
    }
    SECTION("even total") {
        std::vector<int> n1 = {1, 2}, n2 = {3, 4};
        REQUIRE(sol.findMedianSortedArrays(n1, n2) == 2.5);
    }
}
