#include "workspace/src/complicated/dynamic_programming/generate.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("generate Pascal triangle", "[complicated][dp][generate]") {
    using namespace ns_complicated_dynamic_programming_generate;
    Solution sol;
    SECTION("5 rows") {
        auto r = sol.generate(5);
        REQUIRE(r.size() == 5);
        REQUIRE((r[0] == std::vector<int>{1}));
        REQUIRE((r[1] == std::vector<int>{1, 1}));
        REQUIRE((r[2] == std::vector<int>{1, 2, 1}));
        REQUIRE((r[4] == std::vector<int>{1, 4, 6, 4, 1}));
    }
    SECTION("1 row") {
        auto r = sol.generate(1);
        REQUIRE(r.size() == 1);
        REQUIRE((r[0] == std::vector<int>{1}));
    }
}
