#include "workspace/src/data_structure/array_and_string/add_two_numbers.cpp"
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

TEST_CASE("addTwoNumbers_array", "[data_structure][array_and_string][add_two_numbers]") {
    using namespace ns_array_add_two_numbers;
    Solution sol;
    SECTION("342 + 465 = 807") {
        auto l1 = makeList({2, 4, 3});
        auto l2 = makeList({5, 6, 4});
        auto result = sol.addTwoNumbers(l1, l2);
        REQUIRE((toVec(result) == std::vector<int>{7, 0, 8}));
    }
}
