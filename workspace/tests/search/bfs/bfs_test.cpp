#include "workspace/src/search/bfs/bfs.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("BFS shortestPath", "[search][bfs]") {
    ns_search_bfs::Solution bfs;

    SECTION("simple path") {
        std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        REQUIRE(bfs.shortestPath(grid) == 4);
    }

    SECTION("detour around wall") {
        std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 0}, {0, 0, 0}};
        REQUIRE(bfs.shortestPath(grid) == 4);
    }

    SECTION("no path") {
        std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
        REQUIRE(bfs.shortestPath(grid) == -1);
    }

    SECTION("start blocked") {
        std::vector<std::vector<int>> grid = {{1, 0}, {0, 0}};
        REQUIRE(bfs.shortestPath(grid) == -1);
    }
}

TEST_CASE("BFS countComponents", "[search][bfs]") {
    ns_search_bfs::Solution bfs;

    SECTION("two components") {
        std::vector<std::vector<int>> grid = {{1, 1, 0}, {0, 0, 0}, {0, 1, 1}};
        REQUIRE(bfs.countComponents(grid) == 2);
    }

    SECTION("all one component") {
        std::vector<std::vector<int>> grid = {{1, 1}, {1, 1}};
        REQUIRE(bfs.countComponents(grid) == 1);
    }

    SECTION("no components") {
        std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
        REQUIRE(bfs.countComponents(grid) == 0);
    }
}
