#include "workspace/src/data_structure/stack_and_queue/eval_rpn.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("evalRPN", "[data_structure][stack_and_queue][eval_rpn]") {
    using namespace ns_data_structure_stack_and_queue_eval_rpn;
    Solution sol;
    SECTION("addition and multiplication") {
        std::vector<std::string> tokens = {"2","1","+","3","*"};
        REQUIRE(sol.evalRPN(tokens) == 9);
    }
    SECTION("division") {
        std::vector<std::string> tokens = {"4","13","5","/","+"};
        REQUIRE(sol.evalRPN(tokens) == 6);
    }
    SECTION("single number") {
        std::vector<std::string> tokens = {"3"};
        REQUIRE(sol.evalRPN(tokens) == 3);
    }
}
