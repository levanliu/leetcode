#include "workspace/src/search/backtracking/letter_combinations.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("letterCombinations", "[search][backtracking][letter_combinations]") {
    using namespace ns_search_backtracking_letter_combinations;
    SECTION("two digits") {
        Solution sol;
        auto result = sol.letterCombinations("23");
        REQUIRE(result.size() == 9);
    }
    SECTION("empty string") {
        Solution sol;
        auto result = sol.letterCombinations("");
        REQUIRE(result.empty());
    }
}
