#include "workspace/src/data_structure/linked_list/is_palindrome.cpp"
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

TEST_CASE("isPalindrome", "[data_structure][linked_list][is_palindrome]") {
    using namespace ns_data_structure_linked_list_is_palindrome;
    Solution sol;
    SECTION("palindrome even") {
        auto head = makeList({1, 2, 2, 1});
        auto res = toVec(head);
        REQUIRE(res == std::vector<int>{1, 2, 2, 1});
        REQUIRE(sol.isPalindrome(head) == true);
    }
    SECTION("not palindrome") {
        auto head = makeList({1, 2});
        REQUIRE(sol.isPalindrome(head) == false);
    }
    SECTION("single element") {
        auto head = makeList({1});
        REQUIRE(sol.isPalindrome(head) == true);
    }
}
