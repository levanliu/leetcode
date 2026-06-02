#include "workspace/src/skills/binary_search/first_bad_version.cpp"
#include <catch2/catch_test_macros.hpp>

// Note: isBadVersion always returns false in this implementation.
// The binary search converges to n (last version).

TEST_CASE("firstBadVersion", "[skills][binary_search][first_bad_version]") {
    using namespace ns_skills_binary_search_first_bad_version;
    Solution sol;
    SECTION("n=5 stub returns n") {
        REQUIRE(sol.firstBadVersion(5) == 5);
    }
    SECTION("n=1 stub returns 1") {
        REQUIRE(sol.firstBadVersion(1) == 1);
    }
}
