#include "workspace/src/skills/sliding_window/sliding_window_1052.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("maxSatisfied1052", "[skills][sliding_window][sliding_window_1052]") {
    using namespace ns_skills_sliding_window_p_1052;
    Solution sol;
    SECTION("basic") {
        std::vector<int> customers = {1,0,1,2,1,1,7,5};
        std::vector<int> grumpy    = {0,1,0,1,0,1,0,1};
        REQUIRE(sol.maxSatisfied(customers, grumpy, 3) == 16);
    }
    SECTION("single") {
        std::vector<int> customers = {1};
        std::vector<int> grumpy    = {0};
        REQUIRE(sol.maxSatisfied(customers, grumpy, 1) == 1);
    }
}
