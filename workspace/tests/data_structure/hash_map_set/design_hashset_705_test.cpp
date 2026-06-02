#include "workspace/src/data_structure/hash_map_set/design_hashset_705.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("designHashset", "[data_structure][hash_map_set][design_hashset]") {
    using namespace ns_hash_design_hashset;
    Solution hs;
    hs.add(1);
    hs.add(2);
    REQUIRE(hs.contains(1) == true);
    REQUIRE(hs.contains(3) == false);
    hs.add(2);
    REQUIRE(hs.contains(2) == true);
    hs.remove(2);
    REQUIRE(hs.contains(2) == false);
}
