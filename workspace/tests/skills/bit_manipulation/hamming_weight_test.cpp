#include "workspace/src/skills/bit_manipulation/hamming_weight.cpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdint>

TEST_CASE("hammingWeight", "[skills][bit_manipulation][hamming_weight]") {
    using namespace ns_skills_bit_manipulation_hamming_weight;
    Solution sol;
    REQUIRE(sol.hammingWeight(11) == 3);
    REQUIRE(sol.hammingWeight(128) == 1);
    REQUIRE(sol.hammingWeight(0xffffffffu) == 32);
    REQUIRE(sol.hammingWeight(0) == 0);
}
