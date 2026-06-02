#include "workspace/src/complicated/dynamic_programming/coin_change_322.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("coinChange322", "[complicated][dp][coin_change_322]") {
    using namespace ns_dp_coin_change;
    SECTION("basic") {
        Solution sol;
        std::vector<int> coins = {1, 5, 10};
        REQUIRE(sol.coinChange(coins, 11) == 2);
    }
    SECTION("impossible") {
        Solution sol;
        std::vector<int> coins = {2};
        REQUIRE(sol.coinChange(coins, 3) == -1);
    }
    SECTION("zero amount") {
        Solution sol;
        std::vector<int> coins = {1};
        REQUIRE(sol.coinChange(coins, 0) == 0);
    }
}
