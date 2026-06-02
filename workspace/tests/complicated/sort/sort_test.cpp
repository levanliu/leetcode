#include "workspace/src/complicated/sort/sort.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

using namespace ns_complicated_sort;

static const std::vector<int> kExpected = {1, 2, 3, 4, 5};

TEST_CASE("QuickSort", "[complicated][sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5};
    Solution::quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    REQUIRE(arr == std::vector<int>{1, 1, 3, 4, 5});
}

TEST_CASE("MergeSort", "[complicated][sort]") {
    std::vector<int> arr = {5, 3, 1, 4, 2};
    Solution::mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    REQUIRE(arr == kExpected);
}

TEST_CASE("HeapSort", "[complicated][sort]") {
    std::vector<int> arr = {5, 3, 1, 4, 2};
    Solution::heapSort(arr);
    REQUIRE(arr == kExpected);
}

TEST_CASE("kthSmallest", "[complicated][sort]") {
    std::vector<int> arr = {5, 3, 1, 4, 2};
    REQUIRE(Solution::kthSmallest(arr, 1) == 1);
    REQUIRE(Solution::kthSmallest(arr, 3) == 3);
    REQUIRE(Solution::kthSmallest(arr, 5) == 5);
}
