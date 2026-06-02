#include "workspace/src/data_structure/array_and_string/shuffle_array.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("shuffleArray", "[data_structure][array_and_string][shuffle_array]") {
    using namespace ns_data_structure_array_and_string_shuffle_array;
    SECTION("reset returns original") {
        std::vector<int> nums = {1, 2, 3};
        Solution sol(nums);
        sol.shuffle();
        auto r = sol.reset();
        REQUIRE((r == std::vector<int>{1, 2, 3}));
    }
    SECTION("shuffle has same elements") {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        Solution sol(nums);
        auto r = sol.shuffle();
        REQUIRE(r.size() == 5);
        std::sort(r.begin(), r.end());
        REQUIRE((r == std::vector<int>{1, 2, 3, 4, 5}));
    }
}
