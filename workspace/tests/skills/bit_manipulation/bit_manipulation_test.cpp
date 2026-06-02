#include "workspace/src/skills/bit_manipulation/bit_manipulation.cpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace ns_skills_bit_manipulation;

TEST_CASE("singleNumber", "[skills][bit_manipulation]") {
    REQUIRE(Solution::singleNumber({2, 2, 1}) == 1);
    REQUIRE(Solution::singleNumber({4, 1, 2, 1, 2}) == 4);
}

TEST_CASE("singleNumberII (two unique)", "[skills][bit_manipulation]") {
    auto [a, b] = Solution::singleNumberII({1, 2, 1, 3, 2, 5});
    std::vector<int> res = {a, b};
    std::sort(res.begin(), res.end());
    REQUIRE(res == std::vector<int>{3, 5});
}

TEST_CASE("countBits", "[skills][bit_manipulation]") {
    REQUIRE(Solution::countBits(0) == 0);
    REQUIRE(Solution::countBits(7) == 3);
    REQUIRE(Solution::countBits(128) == 1);
}

TEST_CASE("countBitsRange", "[skills][bit_manipulation]") {
    auto res = Solution::countBitsRange(5);
    REQUIRE(res == std::vector<int>{0, 1, 1, 2, 1, 2});
}

TEST_CASE("isPowerOfTwo", "[skills][bit_manipulation]") {
    REQUIRE(Solution::isPowerOfTwo(1));
    REQUIRE(Solution::isPowerOfTwo(16));
    REQUIRE_FALSE(Solution::isPowerOfTwo(0));
    REQUIRE_FALSE(Solution::isPowerOfTwo(3));
}

TEST_CASE("reverseBits", "[skills][bit_manipulation]") {
    REQUIRE(Solution::reverseBits(0b00000010100101000001111010011100u) ==
            0b00111001011110000010100101000000u);
}

TEST_CASE("hammingDistance", "[skills][bit_manipulation]") {
    REQUIRE(Solution::hammingDistance(1, 4) == 2);
    REQUIRE(Solution::hammingDistance(3, 1) == 1);
}
