#include "workspace/src/complicated/dynamic_programming/rob.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("rob", "[complicated][dp][rob]") {
    using namespace ns_complicated_dynamic_programming_rob;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 2, 3, 1};
        REQUIRE(sol.rob(nums) == 4);
    }
    SECTION("another") {
        std::vector<int> nums = {2, 7, 9, 3, 1};
        REQUIRE(sol.rob(nums) == 12);
    }
    SECTION("single") {
        std::vector<int> nums = {5};
        REQUIRE(sol.rob(nums) == 5);
    }
}
