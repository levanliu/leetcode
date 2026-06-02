#include <catch2/catch_test_macros.hpp>
#include "workspace/src/search/shortest_path/shortest_path.cpp"
#include <climits>

TEST_CASE("Dijkstra shortest path", "[search][shortest_path]") {
    ns_search_shortest_path::Solution dij;

    SECTION("simple graph 0->1->2") {
        // 0 --(1)--> 1 --(2)--> 2
        ns_search_shortest_path::Solution::Graph g(3);
        g[0].push_back({1, 1});
        g[1].push_back({2, 2});
        auto dist = dij.shortestPath(3, g, 0);
        REQUIRE(dist[0] == 0);
        REQUIRE(dist[1] == 1);
        REQUIRE(dist[2] == 3);
    }

    SECTION("unreachable node") {
        ns_search_shortest_path::Solution::Graph g(3);
        g[0].push_back({1, 1});
        auto dist = dij.shortestPath(3, g, 0);
        REQUIRE(dist[2] == INT_MAX);
    }

    SECTION("multiple paths, pick shortest") {
        // 0--(10)-->2, 0--(1)-->1--(1)-->2
        ns_search_shortest_path::Solution::Graph g(3);
        g[0].push_back({1, 1});
        g[0].push_back({2, 10});
        g[1].push_back({2, 1});
        auto dist = dij.shortestPath(3, g, 0);
        REQUIRE(dist[2] == 2);
    }
}
