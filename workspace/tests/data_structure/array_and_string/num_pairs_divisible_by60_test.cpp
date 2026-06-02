#include "workspace/src/data_structure/array_and_string/num_pairs_divisible_by60.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("numPairsDivisibleBy60", "[data_structure][array_and_string][num_pairs]") {
    using namespace ns_data_structure_array_and_string_num_pairs_divisible_by60;
    Solution sol;
    SECTION("3 pairs") {
        std::vector<int> time = {30, 20, 150, 100, 40};
        REQUIRE(sol.numPairsDivisibleBy60(time) == 3);
    }
    SECTION("1 pair") {
        std::vector<int> time = {60, 60};
        REQUIRE(sol.numPairsDivisibleBy60(time) == 1);
    }
}
