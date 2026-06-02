#include "workspace/src/data_structure/linked_list/copy_list_with_random_pointer_138.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("copyRandomList", "[data_structure][linked_list][copy_list]") {
    using namespace ns_data_structure_linked_list_138_copy_list_with_random_pointer;
    SECTION("two nodes") {
        Solution sol;
        Node* n1 = new Node(7);
        Node* n2 = new Node(13);
        n1->next = n2;
        n1->random = nullptr;
        n2->random = n1;
        Node* copy = sol.copyRandomList(n1);
        REQUIRE(copy != nullptr);
        REQUIRE(copy->val == 7);
        REQUIRE(copy->next->val == 13);
        REQUIRE(copy->next->random == copy);
        REQUIRE(copy != n1);
    }
    SECTION("null") {
        Solution sol;
        REQUIRE(sol.copyRandomList(nullptr) == nullptr);
    }
}
