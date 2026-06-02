#include <catch2/catch_test_macros.hpp>
#include "workspace/src/skills/prefix_sum/prefix_sum.cpp"

TEST_CASE("PrefixSum1D", "[skills][prefix_sum]") {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ns_skills_prefix_sum_1d::Solution ps(nums);

    REQUIRE(ps.query(0, 4) == 15);
    REQUIRE(ps.query(1, 3) == 9);
    REQUIRE(ps.query(0, 0) == 1);
    REQUIRE(ps.query(4, 4) == 5);
}

TEST_CASE("PrefixSum2D", "[skills][prefix_sum]") {
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ns_skills_prefix_sum_2d::Solution ps(mat);

    REQUIRE(ps.query(0, 0, 2, 2) == 45);
    REQUIRE(ps.query(0, 0, 1, 1) == 12);
    REQUIRE(ps.query(1, 1, 2, 2) == 28);
    REQUIRE(ps.query(0, 0, 0, 0) == 1);
}
