#include <catch2/catch_test_macros.hpp>
#include "workspace/src/complicated/topological_sort/topological_sort.cpp"
#include <algorithm>

TEST_CASE("TopologicalSort", "[complicated][topological_sort]") {
    TopologicalSort ts;

    SECTION("simple DAG") {
        // 0 -> 1 -> 3
        // 0 -> 2 -> 3
        std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
        auto order = ts.sort(4, edges);
        REQUIRE(order.size() == 4);
        auto pos = [&](int v) {
            return std::find(order.begin(), order.end(), v) - order.begin();
        };
        REQUIRE(pos(0) < pos(1));
        REQUIRE(pos(0) < pos(2));
        REQUIRE(pos(1) < pos(3));
        REQUIRE(pos(2) < pos(3));
    }

    SECTION("no edges") {
        auto order = ts.sort(3, {});
        REQUIRE(order.size() == 3);
    }

    SECTION("cycle detected returns empty") {
        std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};
        auto order = ts.sort(3, edges);
        REQUIRE(order.empty());
        REQUIRE(ts.hasCycle(3, edges));
    }

    SECTION("no cycle") {
        std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}};
        REQUIRE_FALSE(ts.hasCycle(3, edges));
    }
}
