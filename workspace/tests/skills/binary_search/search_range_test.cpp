#include "workspace/src/skills/binary_search/search_range.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("searchRange", "[skills][binary_search][search_range]") {
    using namespace ns_skills_binary_search_search_range;
    Solution sol;
    SECTION("found range") {
        std::vector<int> nums = {5, 7, 7, 8, 8, 10};
        REQUIRE((sol.searchRange(nums, 8) == std::vector<int>{3, 4}));
    }
    SECTION("not found") {
        std::vector<int> nums = {5, 7, 7, 8, 8, 10};
        REQUIRE((sol.searchRange(nums, 6) == std::vector<int>{-1, -1}));
    }
    SECTION("empty array") {
        std::vector<int> nums = {};
        REQUIRE((sol.searchRange(nums, 0) == std::vector<int>{-1, -1}));
    }
}
