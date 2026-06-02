#include "workspace/src/complicated/monotonic_stack/monotonic_stack.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("MonotonicStack", "[complicated][monotonic_stack]") {
    ns_complicated_monotonic_stack::Solution ms;

    SECTION("prevSmaller") {
        std::vector<int> nums = {2, 1, 5, 6, 2, 3};
        auto res = ms.prevSmaller(nums);
        REQUIRE(res[0] == -1);
        REQUIRE(res[1] == -1);
        REQUIRE(res[2] == 1);
        REQUIRE(res[3] == 2);
        REQUIRE(res[4] == 1);
        REQUIRE(res[5] == 4);
    }

    SECTION("nextGreater") {
        std::vector<int> nums = {4, 5, 2, 25};
        auto res = ms.nextGreater(nums);
        REQUIRE(res[0] == 1);
        REQUIRE(res[1] == 3);
        REQUIRE(res[2] == 3);
        REQUIRE(res[3] == -1);
    }

    SECTION("largestRectangle") {
        REQUIRE(ms.largestRectangle({2, 1, 5, 6, 2, 3}) == 10);
        REQUIRE(ms.largestRectangle({2, 4}) == 4);
        REQUIRE(ms.largestRectangle({1}) == 1);
    }
}
