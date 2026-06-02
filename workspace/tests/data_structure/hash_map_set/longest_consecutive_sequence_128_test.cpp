#include "workspace/src/data_structure/hash_map_set/longest_consecutive_sequence_128.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("longestConsecutive", "[data_structure][hash_map_set][lcs128]") {
    using namespace ns_data_structure_hash_map_set_128_longest_consecutive_sequence;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {100, 4, 200, 1, 3, 2};
        REQUIRE(sol.longestConsecutive(nums) == 4);
    }
    SECTION("already consecutive") {
        std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        REQUIRE(sol.longestConsecutive(nums) == 9);
    }
    SECTION("empty") {
        std::vector<int> nums = {};
        REQUIRE(sol.longestConsecutive(nums) == 0);
    }
}
