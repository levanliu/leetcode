#include "workspace/src/data_structure/hash_map_set/group_anagrams.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <string>
#include <vector>

TEST_CASE("groupAnagrams", "[data_structure][hash_map_set][group_anagrams]") {
    using namespace ns_data_structure_hash_map_set_group_anagrams;
    Solution sol;
    SECTION("basic") {
        std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
        auto result = sol.groupAnagrams(strs);
        REQUIRE(result.size() == 3);
    }
    SECTION("empty") {
        std::vector<std::string> strs = {""};
        auto result = sol.groupAnagrams(strs);
        REQUIRE(result.size() == 1);
    }
}
