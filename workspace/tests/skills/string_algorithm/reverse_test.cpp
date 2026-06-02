#include "workspace/src/skills/string_algorithm/reverse.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("reverseInteger", "[skills][string_algorithm][reverse]") {
    using namespace ns_skills_string_algorithm_reverse;
    Solution sol;
    REQUIRE(sol.reverse(123) == 321);
    REQUIRE(sol.reverse(-123) == -321);
    REQUIRE(sol.reverse(120) == 21);
    REQUIRE(sol.reverse(1534236469) == 0);  // overflow returns 0
}
