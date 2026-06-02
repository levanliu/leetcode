#include "workspace/src/data_structure/array_and_string/double.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("doublePrecision", "[data_structure][array_and_string][double_precision]") {
    using namespace ns_data_structure_array_and_string_double_precision;
    SECTION("returns correct size") {
        auto r = Solution::floatSequence(3);
        REQUIRE(r.size() == 3);
    }
    SECTION("first element is 0.0") {
        auto r = Solution::floatSequence(5);
        REQUIRE(r[0] == 0.0);
    }
}
