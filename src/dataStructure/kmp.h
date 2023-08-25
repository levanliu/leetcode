//
// Created by le on 4/11/2022.
//

#ifndef LANGUAGEBASIC_KMP_H
#define LANGUAGEBASIC_KMP_H

/**
 *   12345678
 *   abababab
 *
 *   00123456
 */
#include "iostream"

using namespace std;

class kmp
{
private:
    string p, s;
    static const int N = 100010;
    int ne[N];

public:
    int KmpMain()
    {
        cin >> s >> p;

        int m = p.size();
        int n = s.size();

        ne[0] = -1;
        for (int i = 1, j = -1; i < m; i++)
        {
            while (j != -1 && p[i] != p[j + 1])
                j = ne[j];
            if (p[i] == p[j + 1])
                j++;
            ne[i] = j;
        }

        for (int i = 0, j = -1; i < n; i++)
        {
            while (j != -1 && s[i] != p[j + 1])
                j = ne[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m - 1)
            {
                cout << i - j << endl;
                cout << s.substr(i - j, m) << endl;
                j = ne[j];
            }
        }
        return 0;
    }
};

#endif // LANGUAGEBASIC_KMP_H
