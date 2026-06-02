#include "workspace/src/data_structure/array_and_string/solution_802.cpp"
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <vector>

TEST_CASE("findPair802", "[data_structure][array_and_string][solution_802]") {
    using namespace ns_data_structure_array_and_string_two_sum_sorted_pairs;
    SECTION("found") {
        std::vector<int> a = {1, 3}, b = {2, 4};
        auto r = Solution::findPair(a, b, 5);
        REQUIRE((r == std::make_pair(0, 1)));
    }
    SECTION("not found") {
        std::vector<int> a = {1, 3}, b = {2, 4};
        auto r = Solution::findPair(a, b, 10);
        REQUIRE((r == std::make_pair(-1, -1)));
    }
}
