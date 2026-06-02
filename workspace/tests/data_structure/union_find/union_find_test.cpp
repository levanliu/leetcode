#include "workspace/src/data_structure/union_find/union_find.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("UnionFind", "[data_structure][union_find]") {
    ns_data_structure_union_find::Solution uf(5);

    SECTION("initially disconnected") {
        REQUIRE_FALSE(uf.connected(1, 2));
        REQUIRE_FALSE(uf.connected(3, 4));
    }

    SECTION("unite and connected") {
        uf.unite(1, 2);
        REQUIRE(uf.connected(1, 2));
        REQUIRE_FALSE(uf.connected(1, 3));
    }

    SECTION("transitive union") {
        uf.unite(1, 2);
        uf.unite(2, 3);
        REQUIRE(uf.connected(1, 3));
    }

    SECTION("self is connected") {
        REQUIRE(uf.connected(1, 1));
    }
}
