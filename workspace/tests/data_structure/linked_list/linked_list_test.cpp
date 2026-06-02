#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/linked_list/linked_list.cpp"

TEST_CASE("LinkedList operations", "[data_structure][linked_list]") {
    LinkedList<int> list;

    REQUIRE(list.empty());

    SECTION("push_front and front") {
        list.push_front(1);
        list.push_front(2);
        list.push_front(3);
        REQUIRE(list.front() == 3);
    }

    SECTION("pop_front") {
        list.push_front(10);
        list.push_front(20);
        list.pop_front();
        REQUIRE(list.front() == 10);
        list.pop_front();
        REQUIRE(list.empty());
    }

    SECTION("empty throws on front") {
        REQUIRE_THROWS_AS(list.front(), std::runtime_error);
    }
}
