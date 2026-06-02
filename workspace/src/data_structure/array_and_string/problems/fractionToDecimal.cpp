#include <iostream>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string ans = "";
        long x = numerator;
        long y = denominator;
        if (x % y == 0)
            return to_string(x / y);
        if ((x < 0) ^ (y < 0))
            ans += "-";
        x = abs(x);
        y = abs(y);
        ans = ans + to_string(x / y) + ".";
        x %= y;
        unordered_map<long, int> pos;
        while (x != 0)
        {
            pos[x] = ans.size();
            x *= 10;
            ans += to_string(x / y);
            x %= y;
            if (pos.count(x))
            {
                ans.insert(pos[x], "(");
                ans += ")";
                break;
            }
        }
        return ans;
    }
};