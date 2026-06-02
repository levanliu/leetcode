#include "workspace/src/data_structure/array_and_string/rotate_image.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("rotateImage", "[data_structure][array_and_string][rotate_image]") {
    using namespace ns_data_structure_array_and_string_rotate_image;
    Solution sol;
    SECTION("3x3") {
        std::vector<std::vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
        sol.rotate(m);
        REQUIRE((m[0] == std::vector<int>{7, 4, 1}));
        REQUIRE((m[1] == std::vector<int>{8, 5, 2}));
        REQUIRE((m[2] == std::vector<int>{9, 6, 3}));
    }
}
