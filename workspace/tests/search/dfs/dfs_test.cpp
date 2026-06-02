#include <catch2/catch_test_macros.hpp>
#include "workspace/src/search/dfs/dfs.cpp"

TEST_CASE("DFS floodFill", "[search][dfs]") {
    ns_search_dfs::Solution dfs;

    SECTION("basic flood fill") {
        std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
        dfs.floodFill(image, 1, 1, 2);
        REQUIRE(image[0][0] == 2);
        REQUIRE(image[0][1] == 2);
        REQUIRE(image[1][2] == 0);
    }

    SECTION("same color no change") {
        std::vector<std::vector<int>> image = {{1, 1}, {1, 1}};
        auto orig = image;
        dfs.floodFill(image, 0, 0, 1);
        REQUIRE(image == orig);
    }
}

TEST_CASE("DFS countPaths", "[search][dfs]") {
    ns_search_dfs::Solution dfs;

    SECTION("2x2 grid has 2 paths") {
        std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
        REQUIRE(dfs.countPaths(grid) == 2);
    }

    SECTION("1x1 grid has 1 path") {
        std::vector<std::vector<int>> grid = {{0}};
        REQUIRE(dfs.countPaths(grid) == 1);
    }

    SECTION("single path around wall") {
        std::vector<std::vector<int>> grid = {{0, 1}, {0, 0}};
        REQUIRE(dfs.countPaths(grid) == 1);
    }
}
