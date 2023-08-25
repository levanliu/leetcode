//
// Created by le on 2022/11/24.
//

#ifndef ACWING_HIGHADD_H
#define ACWING_HIGHADD_H
#include<iostream>
#include<vector>

using namespace std;

class HighAdd {
    vector<int> add(vector<int> &a,vector<int> &b){
        vector<int> res;
        int t = 0;
        for(int i=0;i<a.size() || i<b.size();i++){
            if(i<a.size()) t+=a[i];
            if(i<b.size()) t+=b[i];
            res.push_back(t % 10);
            t/=10;
        }
        if(t) res.push_back(t);
        return res;
    }

    int addMain(){
        string a,b;
        cin >> a >> b;
        vector<int> a1;
        vector<int> b1;
        for(int i=a.size()-1;i>=0;i--){
            a1.push_back(a[i]-'0');
        }
        for(int i=b.size()-1;i>=0;i--){
            b1.push_back(b[i]-'0');
        }
        vector<int> res = add(a1,b1);
        for(int i=res.size()-1;i>=0;i--){
            cout << res[i];
        }
        return 0;
    }


};


#endif //ACWING_HIGHADD_H
