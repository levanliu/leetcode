#include "workspace/src/data_structure/hash_map_set/randomized_set.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("RandomizedSet", "[data_structure][hash_map_set][randomized_set]") {
    using namespace ns_hash_randomized_set;
    Solution rs;
    REQUIRE(rs.insert(1) == true);
    REQUIRE(rs.remove(2) == false);
    REQUIRE(rs.insert(2) == true);
    int r = rs.getRandom();
    REQUIRE((r == 1 || r == 2));
    REQUIRE(rs.remove(1) == true);
    REQUIRE(rs.insert(2) == false);
    REQUIRE(rs.getRandom() == 2);
}
