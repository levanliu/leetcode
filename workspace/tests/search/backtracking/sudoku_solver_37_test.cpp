#include "workspace/src/search/backtracking/sudoku_solver_37.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("solveSudoku", "[search][backtracking][sudoku_solver]") {
    using namespace ns_search_backtracking_37_sudoku_solver;
    SECTION("leetcode example") {
        std::vector<std::vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        Solution sol;
        sol.solveSudoku(board);
        // Verify no empty cells remain
        bool hasDot = false;
        for (auto& row : board)
            for (char c : row)
                if (c == '.') hasDot = true;
        REQUIRE(hasDot == false);
    }
}
