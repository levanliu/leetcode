#ifndef MAIN_STRINGHASH_H
#define MAIN_STRINGHASH_H

#include "iostream"

using namespace std;

typedef unsigned long long ULL;

class stringHash
{
    //(A B C D) -> (1 2 3 4) 1*p^3 + 2*p^2 ... + 4*p^0  mod Q
    // not ref to 0.
    // not exist conflic,  p = 131 or p = 13331   Q = 2^64     99.99%

private:
    static const int N = 100010, P = 131;
    ULL h[N], p[N];
    char str[N];
    int n, m;

public:
    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int main()
    {
        scanf("%d%d%s", &n, &m, str + 1);

        p[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + str[i];
        }

        while (m--)
        {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if (get(l1, r1) == get(l2, r2))
                puts("Yes");
            else
                puts("No");
        }
        return 0;
    }
};

#endif // MAIN_STRINGHASH_H