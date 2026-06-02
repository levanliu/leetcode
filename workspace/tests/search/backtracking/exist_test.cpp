#include "workspace/src/search/backtracking/exist.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("wordExist", "[search][backtracking][exist]") {
    using namespace ns_search_backtracking_exist;
    Solution sol;
    SECTION("found ABCCED") {
        std::vector<std::vector<char>> board = {
            {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        REQUIRE(sol.exist(board, "ABCCED") == true);
    }
    SECTION("found SEE") {
        std::vector<std::vector<char>> board = {
            {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        REQUIRE(sol.exist(board, "SEE") == true);
    }
    SECTION("not found ABCB") {
        std::vector<std::vector<char>> board = {
            {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        REQUIRE(sol.exist(board, "ABCB") == false);
    }
}
