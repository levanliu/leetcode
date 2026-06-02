#include "workspace/src/complicated/dynamic_programming/unique_paths.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("uniquePaths", "[complicated][dp][unique_paths]") {
    using namespace ns_complicated_dynamic_programming_unique_paths;
    Solution sol;
    REQUIRE(sol.uniquePaths(3, 7) == 28);
    REQUIRE(sol.uniquePaths(3, 2) == 3);
    REQUIRE(sol.uniquePaths(1, 1) == 1);
}
