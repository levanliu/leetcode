#include "workspace/src/data_structure/stack_and_queue/min_stack.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("MinStack", "[data_structure][stack_and_queue][min_stack]") {
    using namespace ns_stack_min_stack;
    Solution stk;
    stk.push(-2);
    stk.push(0);
    stk.push(-3);
    REQUIRE(stk.getMin() == -3);
    stk.pop();
    REQUIRE(stk.top() == 0);
    REQUIRE(stk.getMin() == -2);
}
