#include "workspace/src/data_structure/array_and_string/fizz_buzz.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("fizzBuzz", "[data_structure][array_and_string][fizz_buzz]") {
    using namespace ns_data_structure_array_and_string_fizz_buzz;
    SECTION("n=5") {
        auto r = Solution::fizzBuzz(5);
        REQUIRE((r == std::vector<std::string>{"1","2","Fizz","4","Buzz"}));
    }
    SECTION("n=15 last is FizzBuzz") {
        auto r = Solution::fizzBuzz(15);
        REQUIRE(r[14] == "FizzBuzz");
    }
}
