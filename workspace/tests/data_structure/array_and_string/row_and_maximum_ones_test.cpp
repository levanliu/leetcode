#include "workspace/src/data_structure/array_and_string/row_and_maximum_ones.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("rowAndMaximumOnes", "[data_structure][array_and_string][row_and_max_ones]") {
    using namespace ns_array_row_and_max_ones;
    Solution sol;
    SECTION("basic") {
        std::vector<std::vector<int>> mat = {{0,0,0},{0,1,1},{1,1,1}};
        auto r = sol.rowAndMaximumOnes(mat);
        REQUIRE(r[0] == 2);  // row index 2
        REQUIRE(r[1] == 3);  // count of ones
    }
    SECTION("tie") {
        std::vector<std::vector<int>> mat = {{0,1},{1,0}};
        auto r = sol.rowAndMaximumOnes(mat);
        REQUIRE(r[1] == 1);  // 1 one in the winning row
    }
}
