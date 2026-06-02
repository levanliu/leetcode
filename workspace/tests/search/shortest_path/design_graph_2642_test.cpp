#include "workspace/src/search/shortest_path/design_graph_with_shortest_path_calculator_2642.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("designGraph2642", "[search][shortest_path][design_graph]") {
    using namespace ns_shortest_path_design_graph;
    SECTION("basic") {
        std::vector<std::vector<int>> edges = {{0,2,5},{0,1,2},{1,2,1},{3,0,3}};
        Solution sol(4, edges);
        REQUIRE(sol.shortCost(3, 2) == 6);
        REQUIRE(sol.shortCost(0, 3) == -1);
    }
    SECTION("add edge") {
        std::vector<std::vector<int>> edges = {{0,1,1}};
        Solution sol(3, edges);
        REQUIRE(sol.shortCost(0, 2) == -1);
        sol.add({1, 2, 2});
        REQUIRE(sol.shortCost(0, 2) == 3);
    }
}
