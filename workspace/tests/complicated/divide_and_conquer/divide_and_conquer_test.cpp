#include <catch2/catch_test_macros.hpp>
#include "workspace/src/complicated/divide_and_conquer/divide_and_conquer.h"

TEST_CASE("DivideAndConquer", "[complicated][divide_and_conquer]") {
    DivideAndConquer dc;

    SECTION("quickSort") {
        std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
        dc.quickSort(arr, 0, (int)arr.size() - 1);
        REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 4, 5, 6, 9});
    }

    SECTION("quickSort single element") {
        std::vector<int> arr = {42};
        dc.quickSort(arr, 0, 0);
        REQUIRE(arr == std::vector<int>{42});
    }

    SECTION("mergeSort") {
        std::vector<int> arr = {5, 2, 8, 1, 9, 3};
        dc.mergeSort(arr, 0, (int)arr.size() - 1);
        REQUIRE(arr == std::vector<int>{1, 2, 3, 5, 8, 9});
    }

    SECTION("countInversions") {
        std::vector<int> arr = {3, 1, 2};
        REQUIRE(dc.countInversions(arr, 0, (int)arr.size() - 1) == 2);
    }

    SECTION("countInversions sorted has 0") {
        std::vector<int> arr = {1, 2, 3, 4};
        REQUIRE(dc.countInversions(arr, 0, (int)arr.size() - 1) == 0);
    }
}
