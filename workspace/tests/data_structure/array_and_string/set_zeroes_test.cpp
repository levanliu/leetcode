#include "workspace/src/data_structure/array_and_string/set_zeroes.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("setZeroes", "[data_structure][array_and_string][set_zeroes]") {
    using namespace ns_data_structure_array_and_string_set_zeroes;
    SECTION("basic") {
        std::vector<std::vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
        Solution::setZeroes(m);
        REQUIRE((m[0] == std::vector<int>{1, 0, 1}));
        REQUIRE((m[1] == std::vector<int>{0, 0, 0}));
        REQUIRE((m[2] == std::vector<int>{1, 0, 1}));
    }
    SECTION("no zeros") {
        std::vector<std::vector<int>> m = {{1,2},{3,4}};
        Solution::setZeroes(m);
        REQUIRE((m[0] == std::vector<int>{1, 2}));
    }
}
