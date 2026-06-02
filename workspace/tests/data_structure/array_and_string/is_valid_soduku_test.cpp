#include "workspace/src/data_structure/array_and_string/is_valid_soduku.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("isValidSoduku", "[data_structure][array_and_string][is_valid_soduku]") {
    using namespace ns_data_structure_array_and_string_is_valid_soduku;
    Solution sol;
    SECTION("valid board") {
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
        REQUIRE(sol.isValidSoduku(board) == true);
    }
    SECTION("invalid - duplicate in row") {
        std::vector<std::vector<char>> board = {
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        REQUIRE(sol.isValidSoduku(board) == false);
    }
}
