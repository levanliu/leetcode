#include "workspace/src/data_structure/array_and_string/maximize_sum.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("maximizeSum", "[data_structure][array_and_string][maximize_sum]") {
    using namespace ns_data_structure_array_and_string_maximize_sum;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        REQUIRE(sol.maximizeSum(nums, 3) == 18);
    }
    SECTION("single element") {
        std::vector<int> nums = {5};
        REQUIRE(sol.maximizeSum(nums, 3) == 18);
    }
}
