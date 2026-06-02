#include "workspace/src/skills/bit_manipulation/bit_manipulation.cpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("singleNumber", "[skills][bit_manipulation]") {
    REQUIRE(singleNumber({2, 2, 1}) == 1);
    REQUIRE(singleNumber({4, 1, 2, 1, 2}) == 4);
}

TEST_CASE("singleNumberII (two unique)", "[skills][bit_manipulation]") {
    auto [a, b] = singleNumberII({1, 2, 1, 3, 2, 5});
    std::vector<int> res = {a, b};
    std::sort(res.begin(), res.end());
    REQUIRE(res == std::vector<int>{3, 5});
}

TEST_CASE("countBits", "[skills][bit_manipulation]") {
    REQUIRE(countBits(0) == 0);
    REQUIRE(countBits(7) == 3);
    REQUIRE(countBits(128) == 1);
}

TEST_CASE("countBitsRange", "[skills][bit_manipulation]") {
    auto res = countBitsRange(5);
    REQUIRE(res == std::vector<int>{0, 1, 1, 2, 1, 2});
}

TEST_CASE("isPowerOfTwo", "[skills][bit_manipulation]") {
    REQUIRE(isPowerOfTwo(1));
    REQUIRE(isPowerOfTwo(16));
    REQUIRE_FALSE(isPowerOfTwo(0));
    REQUIRE_FALSE(isPowerOfTwo(3));
}

TEST_CASE("reverseBits", "[skills][bit_manipulation]") {
    REQUIRE(reverseBits(0b00000010100101000001111010011100u) ==
            0b00111001011110000010100101000000u);
}

TEST_CASE("hammingDistance", "[skills][bit_manipulation]") {
    REQUIRE(hammingDistance(1, 4) == 2);
    REQUIRE(hammingDistance(3, 1) == 1);
}
