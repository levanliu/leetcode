#include "workspace/src/skills/binary_search/search.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("searchRotated", "[skills][binary_search][search]") {
    using namespace ns_skills_binary_search_search;
    Solution sol;
    SECTION("found target") {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        REQUIRE(sol.search(nums, 0) == 4);
    }
    SECTION("not found") {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        REQUIRE(sol.search(nums, 3) == -1);
    }
    SECTION("not found single") {
        std::vector<int> nums = {1};
        REQUIRE(sol.search(nums, 0) == -1);
    }
}
