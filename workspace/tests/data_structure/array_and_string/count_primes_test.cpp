#include "workspace/src/data_structure/array_and_string/count_primes.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("countPrimes", "[data_structure][array_and_string][count_primes]") {
    using namespace ns_data_structure_array_and_string_count_primes;
    Solution sol;
    REQUIRE(sol.countPrimes(10) == 4);
    REQUIRE(sol.countPrimes(0) == 0);
    REQUIRE(sol.countPrimes(1) == 0);
}
