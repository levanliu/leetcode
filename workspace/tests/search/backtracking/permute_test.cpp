#include "workspace/src/search/backtracking/permute.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("permute", "[search][backtracking][permute]") {
    using namespace ns_search_backtracking_permute;
    SECTION("3 elements") {
        Solution sol;
        std::vector<int> nums = {1, 2, 3};
        auto result = sol.permute(nums);
        REQUIRE(result.size() == 6);
    }
    SECTION("1 element") {
        Solution sol;
        std::vector<int> nums = {1};
        auto result = sol.permute(nums);
        REQUIRE(result.size() == 1);
    }
}
