#include <catch2/catch_test_macros.hpp>
#include "workspace/src/complicated/dynamic_programming/dp.h"

TEST_CASE("DynamicProgramming", "[complicated][dynamic_programming]") {
    DynamicProgramming dp;

    SECTION("fib") {
        REQUIRE(dp.fib(0) == 0);
        REQUIRE(dp.fib(1) == 1);
        REQUIRE(dp.fib(10) == 55);
    }

    SECTION("climbStairs") {
        REQUIRE(dp.climbStairs(1) == 1);
        REQUIRE(dp.climbStairs(2) == 2);
        REQUIRE(dp.climbStairs(5) == 8);
    }

    SECTION("knapsack01") {
        std::vector<int> w = {2, 3, 4, 5};
        std::vector<int> v = {3, 4, 5, 6};
        REQUIRE(dp.knapsack01(w, v, 8) == 10);
    }

    SECTION("lcs") {
        REQUIRE(dp.lcs("abcde", "ace") == 3);
        REQUIRE(dp.lcs("abc", "abc") == 3);
        REQUIRE(dp.lcs("abc", "def") == 0);
    }

    SECTION("coinChange") {
        REQUIRE(dp.coinChange({1, 5, 11}, 15) == 3);
        REQUIRE(dp.coinChange({2}, 3) == -1);
        REQUIRE(dp.coinChange({1, 2, 5}, 11) == 3);
    }
}
