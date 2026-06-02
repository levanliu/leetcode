#include "workspace/src/data_structure/array_and_string/plus_one.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("plusOne", "[data_structure][array_and_string][plus_one]") {
    using namespace ns_data_structure_array_and_string_plus_one;
    Solution sol;
    SECTION("basic") {
        std::vector<int> d = {1, 2, 3};
        REQUIRE((sol.plusOne(d) == std::vector<int>{1, 2, 4}));
    }
    SECTION("carry") {
        std::vector<int> d = {9};
        REQUIRE((sol.plusOne(d) == std::vector<int>{1, 0}));
    }
    SECTION("all nines") {
        std::vector<int> d = {9, 9, 9};
        REQUIRE((sol.plusOne(d) == std::vector<int>{1, 0, 0, 0}));
    }
}
