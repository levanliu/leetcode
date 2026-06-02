#include "workspace/src/skills/two_pointers/remove_duplicates.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("removeDuplicates", "[skills][two_pointers][remove_duplicates]") {
    using namespace ns_skills_two_pointers_remove_duplicates;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 1, 2};
        int k = sol.removeDuplicates(nums);
        REQUIRE(k == 2);
        REQUIRE(nums[0] == 1);
        REQUIRE(nums[1] == 2);
    }
    SECTION("longer") {
        std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k = sol.removeDuplicates(nums);
        REQUIRE(k == 5);
    }
}
