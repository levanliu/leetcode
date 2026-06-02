#include "workspace/src/complicated/dynamic_programming/max_profit.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("maxProfit", "[complicated][dp][max_profit]") {
    using namespace ns_complicated_dynamic_programming_max_profit;
    Solution sol;
    SECTION("basic") {
        std::vector<int> prices = {7, 1, 5, 3, 6, 4};
        REQUIRE(sol.maxProfit(prices) == 5);
    }
    SECTION("no profit") {
        std::vector<int> prices = {7, 6, 4, 3, 1};
        REQUIRE(sol.maxProfit(prices) == 0);
    }
    SECTION("two elements") {
        std::vector<int> prices = {1, 2};
        REQUIRE(sol.maxProfit(prices) == 1);
    }
}
