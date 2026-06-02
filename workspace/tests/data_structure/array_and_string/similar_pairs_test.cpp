#include "workspace/src/data_structure/array_and_string/similar_pairs.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("similarPairs", "[data_structure][array_and_string][similar_pairs]") {
    using namespace ns_array_similar_pairs;
    Solution sol;
    SECTION("basic") {
        std::vector<std::string> words = {"aba","aabb","abcd","bac","aabc"};
        REQUIRE(sol.similarPairs(words) == 2);
    }
    SECTION("all different") {
        std::vector<std::string> words = {"ab","cd","ef"};
        REQUIRE(sol.similarPairs(words) == 0);
    }
}
