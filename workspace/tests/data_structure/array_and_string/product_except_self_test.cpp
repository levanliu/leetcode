#include "workspace/src/data_structure/array_and_string/product_except_self.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("productExcepSelf", "[data_structure][array_and_string][product_except_self]") {
    using namespace ns_data_structure_array_and_string_product_except_self;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 2, 3, 4};
        REQUIRE((sol.productExcepSelf(nums) == std::vector<int>{24, 12, 8, 6}));
    }
    SECTION("with zero") {
        std::vector<int> nums = {-1, 1, 0, -3, 3};
        auto r = sol.productExcepSelf(nums);
        REQUIRE(r[2] == 9);  // all but index 2 = -1*1*-3*3=9
    }
}
