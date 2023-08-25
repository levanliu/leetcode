//
// Created by le on 3/1/2023.
//

#ifndef MAIN_MAXCOUNT_H
#define MAIN_MAXCOUNT_H
#include<iostream>

using namespace std;

class MaxCount {
private:
    int n;
    static const int N=100010;
    int a[N][2];
public:
    int maxCountMain(){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1];
        }
        int res = 1,ans = 1;
        for(int i=0,j=1;j<n;j++){
            if(a[i][0] == a[j][0] && a[i][1] == a[j][1]){
                res++;
                ans = max(ans,res);
            }else{
                res = 1;
                i = j;
            }

        }
        cout << ans;
        return 0;
    }
};


#endif //MAIN_MAXCOUNT_H
