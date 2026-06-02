#include "workspace/src/complicated/dynamic_programming/climb_stairs.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("climbStairs", "[complicated][dp][climb_stairs]") {
    using namespace ns_complicated_dynamic_programming_climb_stairs;
    Solution sol;
    REQUIRE(sol.climbStairs(1) == 1);
    REQUIRE(sol.climbStairs(2) == 2);
    REQUIRE(sol.climbStairs(3) == 3);
    REQUIRE(sol.climbStairs(5) == 8);
    REQUIRE(sol.climbStairs(10) == 89);
}
