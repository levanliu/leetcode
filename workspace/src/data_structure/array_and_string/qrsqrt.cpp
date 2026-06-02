// Fast inverse square root (Quake III algorithm) using memcpy for C++17 type punning
#include <cstdint>
#include <cstring>

namespace ns_data_structure_array_and_string_qrsqrt {

class Solution {
public:
    // Returns 1/sqrt(number), approximately.
    static float fastInverseSqrt(float number) {
        const float x2 = number * 0.5F;
        static constexpr float kThreeHalfs = 1.5F;
        std::uint32_t i;
        std::memcpy(&i, &number, sizeof(i));
        i = 0x5f3759df - (i >> 1);
        float y;
        std::memcpy(&y, &i, sizeof(y));
        y = y * (kThreeHalfs - (x2 * y * y));  // 1st Newton step
        y = y * (kThreeHalfs - (x2 * y * y));  // 2nd Newton step
        return y;
    }
};

}  // namespace ns_data_structure_array_and_string_qrsqrt
