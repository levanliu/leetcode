#include "workspace/src/data_structure/array_and_string/say.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("inEnglish", "[data_structure][array_and_string][say]") {
    using namespace ns_data_structure_array_and_string_say;
    REQUIRE(Solution::inEnglish(0) == "zero");
    REQUIRE(Solution::inEnglish(1) == "one");
    REQUIRE(Solution::inEnglish(10) == "ten");
}
