#include "workspace/src/data_structure/array_and_string/increasing_triplet.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("increasingTriplet", "[data_structure][array_and_string][increasing_triplet]") {
    using namespace ns_data_structure_array_and_string_increasing_triplet;
    Solution sol;
    SECTION("exists") {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        REQUIRE(sol.increasingTriplet(nums) == true);
    }
    SECTION("not exists") {
        std::vector<int> nums = {5, 4, 3, 2, 1};
        REQUIRE(sol.increasingTriplet(nums) == false);
    }
}
