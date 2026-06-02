#include "workspace/src/data_structure/array_and_string/my_pow.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("myPow", "[data_structure][array_and_string][my_pow]") {
    using namespace ns_data_structure_array_and_string_my_pow;
    Solution sol;
    REQUIRE(sol.myPow(2.0, 10) == 1024.0);
    REQUIRE(sol.myPow(2.0, 0) == 1.0);
    REQUIRE(sol.myPow(2.0, -2) == 0.25);
}
