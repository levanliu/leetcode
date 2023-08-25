//
// Created by le on 2/11/2022.
//

#ifndef LANGUAGEBASIC_SINGLESTACK_H
#define LANGUAGEBASIC_SINGLESTACK_H

#include "iostream"
using namespace std;

class SingleStack {
public:
    static const int N=1e5+10;
    int n;
    int stk[N],tt;

    int singleStack(){
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            while(tt && stk[tt] >= x) tt--;
            if(tt) cout << stk[tt] << endl;
            else cout << -1 << ' ';

            stk[++tt] = x;
        }
        return 0;
    }
};


#endif //LANGUAGEBASIC_SINGLESTACK_H
