#include "workspace/src/complicated/dynamic_programming/coin_change.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("coinChange", "[complicated][dp][coin_change]") {
    using namespace ns_complicated_dynamic_programming_coin_change;
    Solution sol;
    SECTION("basic") {
        std::vector<int> coins = {1, 5, 10};
        REQUIRE(sol.coinChange(coins, 11) == 2);
    }
    SECTION("impossible") {
        std::vector<int> coins = {2};
        REQUIRE(sol.coinChange(coins, 3) == -1);
    }
    SECTION("exact match") {
        std::vector<int> coins = {5};
        REQUIRE(sol.coinChange(coins, 5) == 1);
    }
}
