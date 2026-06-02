#include <catch2/catch_test_macros.hpp>
#include "workspace/src/search/backtracking/n_queens.cpp"

TEST_CASE("NQueens", "[search][backtracking]") {
    NQueens nq;

    SECTION("n=1 has 1 solution") {
        REQUIRE(nq.countSolutions(1) == 1);
    }

    SECTION("n=4 has 2 solutions") {
        REQUIRE(nq.countSolutions(4) == 2);
    }

    SECTION("n=8 has 92 solutions") {
        REQUIRE(nq.countSolutions(8) == 92);
    }

    SECTION("solve n=4 returns 2 valid boards") {
        auto solutions = nq.solve(4);
        REQUIRE(solutions.size() == 2);
        for (const auto& board : solutions) {
            REQUIRE((int)board.size() == 4);
            for (const auto& row : board) {
                int queens = 0;
                for (char c : row) if (c == 'Q') queens++;
                REQUIRE(queens == 1);
            }
        }
    }
}
