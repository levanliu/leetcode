#include "workspace/src/data_structure/array_and_string/my_sqrt.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("mySqrt", "[data_structure][array_and_string][my_sqrt]") {
    using namespace ns_data_structure_array_and_string_my_sqrt;
    Solution sol;
    REQUIRE(sol.mySqrt(4) == 2);
    REQUIRE(sol.mySqrt(8) == 2);
    REQUIRE(sol.mySqrt(0) == 0);
    REQUIRE(sol.mySqrt(9) == 3);
}
