#include "workspace/src/data_structure/linked_list/delete_node.cpp"
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

TEST_CASE("deleteNode", "[data_structure][linked_list][delete_node]") {
    using namespace ns_data_structure_linked_list_delete_node;
    Solution sol;
    SECTION("delete middle node") {
        auto head = makeList({4, 5, 1, 9});
        ListNode* to_delete = head->next;  // node with val=5
        sol.deleteNode(to_delete);
        REQUIRE((toVec(head) == std::vector<int>{4, 1, 9}));
    }
}
