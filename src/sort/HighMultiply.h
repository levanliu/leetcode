//
// Created by le on 2022/11/24.
//

#ifndef ACWING_HIGHMULTIPLY_H
#define ACWING_HIGHMULTIPLY_H

#include<iostream>
#include<vector>

using namespace std;

class HighMultiply {


    vector<int> multi(vector<int> A,int b){
        vector<int> res;

        int t = 0;
        for(int i=0;i<A.size() || t;i++){
            if(i<A.size()) t += A[i] * b;
            res.push_back(t%10);
            t/=10;
        }

        while(res.size()>1 && res.back()==0) res.pop_back();
        return res;
    }

    int mulityplyMain(){
        string a;
        int b;
        cin >> a >> b;
        vector<int> A;
        for(int i=a.size()-1;i>=0;i--){
            A.push_back(a[i]-'0');
        }
        vector<int> C = multi(A,b);
        for(int i=C.size()-1;i>=0;i--){
            cout << C[i];
        }
        return 0;
    }


};


#endif //ACWING_HIGHMULTIPLY_H
