#include <climits>
#include <cstdint>
#include <bit>
#include <limits>
#include <cstdint>
#include <iostream>
using namespace std;

/**
//gcc 13.1
//-std=c++2a -mx32 -O3
constexpr float Q_rsqrtc20(float number) noexcept
{
	static_assert(std::numeric_limits<float>::is_iec559); // Проверка совместимости целевой машины

	float const y = std::bit_cast<float>(
		0x5f3759df - (std::bit_cast<std::uint32_t>(number) >> 1));
	return y * (1.5f - (number * 0.5f * y * y));
}
*/

float Q_rsqrt(float number) {
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F; //target number;
  y = number;

  i = *(long *)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(float *)&i;
  // f(y) = 1/y^2 -x
  // f'(y) = -2/y^3
  y = y * (threehalfs - (x2 * y * y)); // yn+1 = yn *(1.5 - (x/2) * yn * yn)
  y = y * (threehalfs - (x2 * y * y));

  return y;
}

int main() {
  float a;
  std::cin >> a;
  std::cout << Q_rsqrt(a) << std::endl;
  std::cout << sizeof(float) * CHAR_BIT << std::endl;
  return 0;
}
