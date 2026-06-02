#include "workspace/src/data_structure/linked_list/remove_nth_from_end.cpp"
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

TEST_CASE("removeNthFromEnd", "[data_structure][linked_list][remove_nth]") {
    using namespace ns_data_structure_linked_list_remove_nth_from_end;
    Solution sol;
    SECTION("remove 2nd from end") {
        auto head = makeList({1, 2, 3, 4, 5});
        auto result = sol.removeNthFromEnd(head, 2);
        REQUIRE((toVec(result) == std::vector<int>{1, 2, 3, 5}));
    }
    SECTION("remove only element") {
        auto head = makeList({1});
        auto result = sol.removeNthFromEnd(head, 1);
        REQUIRE(result == nullptr);
    }
    SECTION("remove first from 2 elements") {
        auto head = makeList({1, 2});
        auto result = sol.removeNthFromEnd(head, 2);
        REQUIRE((toVec(result) == std::vector<int>{2}));
    }
}
