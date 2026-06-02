#include "workspace/src/data_structure/array_and_string/data_statistics.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("dataStatistics", "[data_structure][array_and_string][data_statistics]") {
    using namespace ns_data_structure_array_and_string_data_statistics;
    SECTION("basic") {
        std::vector<int> data = {1, 2, 3, 4, 5};
        auto s = Solution::computeStats(data);
        REQUIRE(s.minVal == 1);
        REQUIRE(s.maxVal == 5);
        REQUIRE(s.avg == 3.0);
    }
    SECTION("single element") {
        std::vector<int> data = {7};
        auto s = Solution::computeStats(data);
        REQUIRE(s.minVal == 7);
        REQUIRE(s.maxVal == 7);
        REQUIRE(s.avg == 7.0);
    }
}
