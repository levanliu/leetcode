// acwing 5279 — Snail climbing well: 5m up per day, 4m down per night.
// Returns the day number (1-indexed) when it reaches the top.
#include <algorithm>

namespace ns_data_structure_array_and_string_snail {

class Solution {
public:
    // Well depth n metres. Snail climbs 5m/day, slides 4m/night.
    // Formula: at end of day d the snail has climbed min(5d, d-1 + 5) metres.
    // Simplifies to: reaches top on day max(1, n-4).
    static int daysToClimb(int n) { return std::max(1, n - 4); }
};

}  // namespace ns_data_structure_array_and_string_snail
