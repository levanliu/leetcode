#include "workspace/src/data_structure/linked_list/has_cycle.cpp"
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
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

TEST_CASE("hasCycle", "[data_structure][linked_list][has_cycle]") {
    using namespace ns_data_structure_linked_list_has_cycle;
    Solution sol;
    SECTION("no cycle") {
        auto head = makeList({1, 2, 3, 4});
        auto res = toVec(head);
        REQUIRE(res == std::vector<int>{1, 2, 3, 4});
        REQUIRE(sol.hasCycle(head) == false);
    }
    SECTION("with cycle") {
        auto head = makeList({3, 2, 0, -4});
        // Create cycle: tail -> second node
        ListNode* tail = head->next->next->next;
        tail->next = head->next;
        REQUIRE(sol.hasCycle(head) == true);
        // Fix cycle before memory cleanup
        tail->next = nullptr;
    }
    SECTION("single node no cycle") {
        auto head = new ListNode(1);
        REQUIRE(sol.hasCycle(head) == false);
    }
}
