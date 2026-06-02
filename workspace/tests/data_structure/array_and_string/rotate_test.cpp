#include "workspace/src/data_structure/array_and_string/rotate.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("rotateArray", "[data_structure][array_and_string][rotate]") {
    using namespace ns_data_structure_array_and_string_rotate;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        sol.rotate(nums, 3);
        REQUIRE((nums == std::vector<int>{5, 6, 7, 1, 2, 3, 4}));
    }
    SECTION("k = 0") {
        std::vector<int> nums = {1, 2, 3};
        sol.rotate(nums, 0);
        REQUIRE((nums == std::vector<int>{1, 2, 3}));
    }
}
