#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
const double pi = acos(-1);
int main()
{
    double r, h;
    std::cin >> r >> h;
    double surface = pi * r * r + 2 + 2 * pi * r * h;
    std::cout << std::fixed << std::setprecision(3) << surface << std::endl;
    return 0;
}