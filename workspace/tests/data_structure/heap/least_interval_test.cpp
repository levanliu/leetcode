#include "workspace/src/data_structure/heap/least_interval.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("leastInterval", "[data_structure][heap][least_interval]") {
    using namespace ns_data_structure_heap_least_interval;
    Solution sol;
    SECTION("basic") {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        REQUIRE(sol.leastInterval(tasks, 2) == 8);
    }
    SECTION("no cooldown") {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        REQUIRE(sol.leastInterval(tasks, 0) == 6);
    }
}
