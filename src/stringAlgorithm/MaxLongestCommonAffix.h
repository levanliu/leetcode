//
// Created by le on 18/10/2022.
//

#ifndef CPP_MAXLONGESTCOMMONAFFIX_H
#define CPP_MAXLONGESTCOMMONAFFIX_H

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int maxLongestCommonAffix(){
    int n;
    while(cin >> n, n)
    {
        string s, a;
        int MAX = 999999;
        cin >> s;
        for(int i = 1; i < n; ++ i)
        {
            int res = 0;
            cin >> a;
            for(int j = 0; j < a.size() && j < s.size(); ++ j)
                if(a[a.size() - 1 - j] == s[s.size() - 1 - j]) res++;
                else break;
            MAX = min(MAX, res);
        }
        if(MAX) cout << s.substr(s.size()-MAX) << endl;
        else cout << endl;
    }
    return 0;
}

#endif
