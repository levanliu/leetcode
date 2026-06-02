#include "workspace/src/data_structure/stack_and_queue/is_valid.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("isValid", "[data_structure][stack_and_queue][is_valid]") {
    using namespace ns_data_structure_stack_and_queue_is_valid;
    Solution sol;
    REQUIRE(sol.isValid("()") == true);
    REQUIRE(sol.isValid("()[]{}") == true);
    REQUIRE(sol.isValid("(]") == false);
    REQUIRE(sol.isValid("([)]") == false);
    REQUIRE(sol.isValid("{[]}") == true);
    REQUIRE(sol.isValid("") == true);
}
