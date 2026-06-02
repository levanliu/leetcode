#include "workspace/src/data_structure/array_and_string/spiral_order.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("spiralOrder", "[data_structure][array_and_string][spiral_order]") {
    using namespace ns_data_structure_array_and_string_spiral_order;
    SECTION("3x3") {
        Solution sol;
        std::vector<std::vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
        auto r = sol.spiralOrder(m);
        REQUIRE((r == std::vector<int>{1,2,3,6,9,8,7,4,5}));
    }
    SECTION("1x1") {
        Solution sol;
        std::vector<std::vector<int>> m = {{1}};
        auto r = sol.spiralOrder(m);
        REQUIRE((r == std::vector<int>{1}));
    }
}
