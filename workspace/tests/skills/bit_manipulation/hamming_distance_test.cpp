#include "workspace/src/skills/bit_manipulation/hamming_distance.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("hammingDistance", "[skills][bit_manipulation][hamming_distance]") {
    using namespace ns_skills_bit_manipulation_hamming_distance;
    Solution sol;
    REQUIRE(sol.hammingDistance(1, 4) == 2);
    REQUIRE(sol.hammingDistance(3, 1) == 1);
    REQUIRE(sol.hammingDistance(0, 0) == 0);
}
