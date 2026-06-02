#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/heap/heap.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("MaxHeap basic operations", "[data_structure][heap]") {
    ns_data_structure_heap::MaxHeap<int> h;
    h.push(3); h.push(1); h.push(4); h.push(1); h.push(5);

    SECTION("top is max") {
        REQUIRE(h.top() == 5);
    }

    SECTION("pop in descending order") {
        std::vector<int> out;
        while (!h.empty()) { out.push_back(h.top()); h.pop(); }
        REQUIRE(out == std::vector<int>{5, 4, 3, 1, 1});
    }
}

TEST_CASE("MinHeap basic operations", "[data_structure][heap]") {
    ns_data_structure_heap::MinHeap<int> h;
    h.push(3); h.push(1); h.push(4); h.push(1); h.push(5);

    SECTION("top is min") {
        REQUIRE(h.top() == 1);
    }

    SECTION("pop in ascending order") {
        std::vector<int> out;
        while (!h.empty()) { out.push_back(h.top()); h.pop(); }
        REQUIRE(out == std::vector<int>{1, 1, 3, 4, 5});
    }
}

TEST_CASE("Heap build from vector", "[data_structure][heap]") {
    ns_data_structure_heap::MaxHeap<int> h(std::vector<int>{5, 3, 1, 4, 2});
    REQUIRE(h.top() == 5);
    REQUIRE(h.size() == 5);
}

TEST_CASE("Heap topK", "[data_structure][heap]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    auto res = ns_data_structure_heap::MaxHeap<int>::topK(arr, 3);
    std::sort(res.begin(), res.end());
    REQUIRE(res == std::vector<int>{5, 6, 9});
}
