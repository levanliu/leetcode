#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/graph/graph.h"
#include <algorithm>

TEST_CASE("countComponents", "[graph]") {
    REQUIRE(countComponents(5, {{0,1},{1,2},{3,4}}) == 2);
    REQUIRE(countComponents(4, {}) == 4);
    REQUIRE(countComponents(3, {{0,1},{1,2},{0,2}}) == 1);
}

TEST_CASE("hasCycleDirected", "[graph]") {
    Graph acyclic(3);
    acyclic[0].push_back(1); acyclic[1].push_back(2);
    REQUIRE_FALSE(hasCycleDirected(3, acyclic));

    Graph cyclic(3);
    cyclic[0].push_back(1); cyclic[1].push_back(2); cyclic[2].push_back(0);
    REQUIRE(hasCycleDirected(3, cyclic));
}

TEST_CASE("topoSort", "[graph]") {
    // 0->1->3, 0->2->3
    Graph g(4);
    g[0].push_back(1); g[0].push_back(2);
    g[1].push_back(3); g[2].push_back(3);
    auto order = topoSort(4, g);
    REQUIRE(order.size() == 4);
    // 0 must come before 1,2; 1,2 before 3
    auto pos = [&](int v){ return std::find(order.begin(), order.end(), v) - order.begin(); };
    REQUIRE(pos(0) < pos(1));
    REQUIRE(pos(0) < pos(2));
    REQUIRE(pos(1) < pos(3));
    REQUIRE(pos(2) < pos(3));
}

TEST_CASE("topoSort detects cycle", "[graph]") {
    Graph g(2);
    g[0].push_back(1); g[1].push_back(0);
    REQUIRE(topoSort(2, g).empty());
}

TEST_CASE("bfsOrder and dfsOrder", "[graph]") {
    Graph g(4);
    g[0].push_back(1); g[0].push_back(2); g[1].push_back(3);
    auto bfs = bfsOrder(4, g, 0);
    REQUIRE(bfs[0] == 0);
    REQUIRE(bfs.size() == 4);

    auto dfs = dfsOrder(4, g, 0);
    REQUIRE(dfs[0] == 0);
    REQUIRE(dfs.size() == 4);
}

TEST_CASE("isBipartite", "[graph]") {
    // Even cycle: bipartite
    Graph even(4);
    even[0].push_back(1); even[1].push_back(2);
    even[2].push_back(3); even[3].push_back(0);
    REQUIRE(isBipartite(4, even));

    // Odd cycle: not bipartite
    Graph odd(3);
    odd[0].push_back(1); odd[1].push_back(2); odd[2].push_back(0);
    REQUIRE_FALSE(isBipartite(3, odd));
}
