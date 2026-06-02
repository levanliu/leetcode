#include "workspace/src/data_structure/linked_list/reverse_list.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

static ListNode* makeList(std::vector<int> vals) {
    ListNode* head = nullptr;
    for (int i = (int)vals.size() - 1; i >= 0; --i)
        head = new ListNode(vals[i], head);
    return head;
}
static std::vector<int> toVec(ListNode* head) {
    std::vector<int> res;
    while (head) { res.push_back(head->val); head = head->next; }
    return res;
}

TEST_CASE("reverseList", "[data_structure][linked_list][reverse_list]") {
    using namespace ns_data_structure_linked_list_reverse_list;
    Solution sol;
    SECTION("basic") {
        auto head = makeList({1, 2, 3, 4, 5});
        auto result = sol.reverseList(head);
        REQUIRE((toVec(result) == std::vector<int>{5, 4, 3, 2, 1}));
    }
    SECTION("null") {
        REQUIRE(sol.reverseList(nullptr) == nullptr);
    }
    SECTION("single element") {
        auto head = makeList({1});
        auto result = sol.reverseList(head);
        REQUIRE((toVec(result) == std::vector<int>{1}));
    }
}
