#include "workspace/src/complicated/dynamic_programming/can_jump.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("canJump", "[complicated][dp][can_jump]") {
    using namespace ns_complicated_dynamic_programming_can_jump;
    SECTION("can reach end") {
        std::vector<int> nums = {2, 3, 1, 1, 4};
        REQUIRE(Solution{}.canJump(nums) == true);
    }
    SECTION("cannot reach end") {
        std::vector<int> nums = {3, 2, 1, 0, 4};
        REQUIRE(Solution{}.canJump(nums) == false);
    }
    SECTION("single element") {
        std::vector<int> nums = {0};
        REQUIRE(Solution{}.canJump(nums) == true);
    }
}
