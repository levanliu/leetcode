#include "workspace/src/data_structure/linked_list/merge_two_lists.cpp"
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

TEST_CASE("mergeTwoLists", "[data_structure][linked_list][merge_two_lists]") {
    using namespace ns_data_structure_linked_list_merge_two_lists;
    Solution sol;
    SECTION("basic") {
        auto l1 = makeList({1, 2, 4});
        auto l2 = makeList({1, 3, 4});
        auto result = sol.mergeTwoLists(l1, l2);
        REQUIRE((toVec(result) == std::vector<int>{1, 1, 2, 3, 4, 4}));
    }
    SECTION("one empty") {
        auto l1 = makeList({});
        auto l2 = makeList({0});
        auto result = sol.mergeTwoLists(l1, l2);
        REQUIRE((toVec(result) == std::vector<int>{0}));
    }
    SECTION("both empty") {
        auto result = sol.mergeTwoLists(nullptr, nullptr);
        REQUIRE(result == nullptr);
    }
}
