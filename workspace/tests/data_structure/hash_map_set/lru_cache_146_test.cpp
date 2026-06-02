#include "workspace/src/data_structure/hash_map_set/lru_cache_146.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("LRUCache", "[data_structure][hash_map_set][lru_cache]") {
    using namespace ns_hash_lru_cache;
    SECTION("basic operations") {
        Solution lru(2);
        lru.put(1, 1);
        lru.put(2, 2);
        REQUIRE(lru.get(1) == 1);
        lru.put(3, 3);
        REQUIRE(lru.get(2) == -1);
        lru.put(4, 4);
        REQUIRE(lru.get(1) == -1);
        REQUIRE(lru.get(3) == 3);
        REQUIRE(lru.get(4) == 4);
    }
}
