#include "workspace/src/data_structure/array_and_string/title_to_number.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("titleToNumber", "[data_structure][array_and_string][title_to_number]") {
    using namespace ns_data_structure_array_and_string_title_to_number;
    Solution sol;
    REQUIRE(sol.titleToNumber("A") == 1);
    REQUIRE(sol.titleToNumber("Z") == 26);
    REQUIRE(sol.titleToNumber("AA") == 27);
    REQUIRE(sol.titleToNumber("AB") == 28);
}
