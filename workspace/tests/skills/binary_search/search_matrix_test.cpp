#include "workspace/src/skills/binary_search/search_matrix.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("searchMatrix", "[skills][binary_search][search_matrix]") {
    using namespace ns_skills_binary_search_search_matrix;
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1,4,7,11,15},{2,5,8,12,19},
        {3,6,9,16,22},{10,13,14,17,24},
        {18,21,23,26,30}};
    SECTION("found 5") {
        REQUIRE(sol.searchMatrix(matrix, 5) == true);
    }
    SECTION("not found 20") {
        REQUIRE(sol.searchMatrix(matrix, 20) == false);
    }
    SECTION("found 1") {
        REQUIRE(sol.searchMatrix(matrix, 1) == true);
    }
}
