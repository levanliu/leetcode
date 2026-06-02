#include "workspace/src/search/backtracking/generate_parenthesis.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

TEST_CASE("generateParenthesis", "[search][backtracking][generate_parenthesis]") {
    using namespace ns_search_backtracking_generate_parenthesis;
    SECTION("n=3") {
        Solution sol;
        auto result = sol.generateParenthesis(3);
        REQUIRE(result.size() == 5);
    }
    SECTION("n=1") {
        Solution sol;
        auto result = sol.generateParenthesis(1);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == "()");
    }
}
