#include "workspace/src/data_structure/array_and_string/surface_areaof_cylinder.cpp"
#include <catch2/catch_test_macros.hpp>
#include <cmath>

TEST_CASE("surfaceAreaCylinder", "[data_structure][array_and_string][surface_area]") {
    using namespace ns_data_structure_array_and_string_surface_area;
    SECTION("r=1 h=1") {
        double r = Solution::surfaceArea(1.0, 1.0);
        REQUIRE(std::fabs(r - 4 * M_PI) < 0.001);
    }
    SECTION("r=0 h=1") {
        double r = Solution::surfaceArea(0.0, 1.0);
        REQUIRE(std::fabs(r - 0.0) < 0.001);
    }
}
