#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/trie/trie.cpp"

TEST_CASE("Trie insert and query", "[data_structure][trie]") {
    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("app");

    SECTION("query exact word") {
        REQUIRE(t.query("apple") == 2);
        REQUIRE(t.query("app") == 1);
    }

    SECTION("query missing word") {
        REQUIRE(t.query("ap") == 0);
        REQUIRE(t.query("banana") == 0);
    }

    SECTION("startsWith prefix") {
        REQUIRE(t.startsWith("app") == true);
        REQUIRE(t.startsWith("ap") == true);
        REQUIRE(t.startsWith("ban") == false);
    }
}
