#include "workspace/src/skills/bit_manipulation/get_sum.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("getSum", "[skills][bit_manipulation][get_sum]") {
    using namespace ns_skills_bit_manipulation_get_sum;
    Solution sol;
    REQUIRE(sol.add(1, 2) == 3);
    REQUIRE(sol.add(0, 0) == 0);
    REQUIRE(sol.sub(5, 3) == 2);
    REQUIRE(sol.multiply(3, 4) == 12);
    REQUIRE(sol.divide(10, 3) == 3);
}
