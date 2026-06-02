#include "workspace/src/skills/two_pointers/move_zeros.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("moveZeros", "[skills][two_pointers][move_zeros]") {
    using namespace ns_skills_two_pointers_move_zeros;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {0, 1, 0, 3, 12};
        sol.moveZeros(nums);
        REQUIRE((nums == std::vector<int>{1, 3, 12, 0, 0}));
    }
    SECTION("all zeros") {
        std::vector<int> nums = {0, 0};
        sol.moveZeros(nums);
        REQUIRE((nums == std::vector<int>{0, 0}));
    }
    SECTION("no zeros") {
        std::vector<int> nums = {1, 2, 3};
        sol.moveZeros(nums);
        REQUIRE((nums == std::vector<int>{1, 2, 3}));
    }
}
