#include "workspace/src/skills/bit_manipulation/reverse_bits.cpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdint>

TEST_CASE("reverseBits", "[skills][bit_manipulation][reverse_bits]") {
    using namespace ns_skills_bit_manipulation_reverse_bits;
    Solution sol;
    REQUIRE(sol.reverseBits(0b00000010100101000001111010011100u) == 964176192u);
    REQUIRE(sol.reverseBits(0xffffffffu) == 0xffffffffu);
    REQUIRE(sol.reverseBits(0u) == 0u);
}
