#include "workspace/src/skills/string_algorithm/reverse_string.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("reverseString", "[skills][string_algorithm][reverse_string]") {
    using namespace ns_skills_string_algorithm_reverse_string;
    Solution sol;
    SECTION("basic") {
        std::vector<char> s = {'h','e','l','l','o'};
        sol.reverseString(s);
        REQUIRE((s == std::vector<char>{'o','l','l','e','h'}));
    }
    SECTION("two chars") {
        std::vector<char> s = {'A','b'};
        sol.reverseString(s);
        REQUIRE((s == std::vector<char>{'b','A'}));
    }
}
