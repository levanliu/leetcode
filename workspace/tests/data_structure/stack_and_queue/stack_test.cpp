#include "workspace/src/data_structure/stack_and_queue/stack.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stack operations", "[data_structure][stack_and_queue]") {
    ns_data_structure_stack_and_queue::Solution<int> s;

    REQUIRE(s.empty());
    REQUIRE(s.size() == 0);

    SECTION("push and top") {
        s.push(1);
        s.push(2);
        s.push(3);
        REQUIRE(s.top() == 3);
        REQUIRE(s.size() == 3);
    }

    SECTION("pop reduces size") {
        s.push(10);
        s.push(20);
        s.pop();
        REQUIRE(s.top() == 10);
        REQUIRE(s.size() == 1);
    }

    SECTION("underflow throws") {
        REQUIRE_THROWS_AS(s.pop(), std::runtime_error);
        REQUIRE_THROWS_AS(s.top(), std::runtime_error);
    }
}
