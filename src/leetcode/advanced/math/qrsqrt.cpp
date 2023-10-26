#include <bits/stdc++.h>
#include <climits>
using namespace std;

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
  cin >> a;
  cout << Q_rsqrt(a) << endl;
  cout << sizeof(float) * CHAR_BIT << endl;
  return 0;
}
