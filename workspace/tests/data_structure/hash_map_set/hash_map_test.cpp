#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/hash_map_set/hash_map.h"
#include <string>

TEST_CASE("HashMap operations", "[data_structure][hash_map_set]") {
    HashMap<std::string, int> map;

    REQUIRE(map.empty());
    REQUIRE(map.size() == 0);

    SECTION("insert and contains") {
        map.insert("a", 1);
        map.insert("b", 2);
        REQUIRE(map.contains("a"));
        REQUIRE(map.contains("b"));
        REQUIRE_FALSE(map.contains("c"));
        REQUIRE(map.size() == 2);
    }

    SECTION("get value") {
        map.insert("key", 42);
        REQUIRE(map.get("key") == 42);
    }

    SECTION("update existing key") {
        map.insert("x", 1);
        map.insert("x", 99);
        REQUIRE(map.get("x") == 99);
        REQUIRE(map.size() == 1);
    }

    SECTION("remove") {
        map.insert("del", 5);
        REQUIRE(map.contains("del"));
        map.remove("del");
        REQUIRE_FALSE(map.contains("del"));
        REQUIRE(map.size() == 0);
    }

    SECTION("get missing key throws") {
        REQUIRE_THROWS_AS(map.get("missing"), std::out_of_range);
    }
}
