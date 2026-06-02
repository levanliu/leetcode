#include <iostream>
using namespace std;
namespace ns_skills_string_algorithm_reverse {

class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int t = x % 10;
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            res = res * 10 + t;
            x = x / 10;
        }
        return res;
    }
};
} // namespace ns_skills_string_algorithm_reverse
