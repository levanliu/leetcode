#include "workspace/src/data_structure/array_and_string/intersect.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("intersect", "[data_structure][array_and_string][intersect]") {
    using namespace ns_data_structure_array_and_string_intersect;
    Solution sol;
    SECTION("basic") {
        std::vector<int> n1 = {1, 2, 2, 1}, n2 = {2, 2};
        auto r = sol.intersect(n1, n2);
        REQUIRE((r == std::vector<int>{2, 2}));
    }
    SECTION("no common") {
        std::vector<int> n1 = {1, 2}, n2 = {3, 4};
        auto r = sol.intersect(n1, n2);
        REQUIRE(r.empty());
    }
}
