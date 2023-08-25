//
// Created by le on 2022/11/24.
//

#ifndef ACWING_HIGHSUB_H
#define ACWING_HIGHSUB_H

#include<iostream>
#include<vector>
#include<cstdio>


using namespace std;
class HighSub {


    bool cmp(vector<int> &A,vector<int> &B){
        if(A.size() !=  B.size()) return A.size() > B.size();
        for(int i=A.size()-1;i>=0;i--){
            if(A[i] != B[i]){
                return A[i] > B[i];
            }
        }
        return true;
    }

    vector<int> sub(vector<int> &A,vector<int> &B){
        vector<int> C;
        int t = 0;
        for(int i=0;i<A.size();i++){
            t = A[i] - t;
            if(i<B.size()) t-=B[i];
            C.push_back((t+10)%10);
            if(t<0){
                t = 1;
            }else{
                t = 0;
            }
        }

        while(C.size() > 1 && C[C.size()-1]==0 ) C.pop_back();

        return C;
    }

    int subMain(){
        string  a,b;
        cin>> a >> b;
        vector<int> A,B;
        for(int i=a.size()-1;i>=0;i--){
            A.push_back(a[i]-'0');
        }

        for(int i=b.size()-1;i>=0;i--){
            B.push_back(b[i]-'0');
        }

        if(cmp(A,B)){
            vector<int> C = sub(A,B);
            for(int i=C.size()-1;i>=0;i-- ){
                cout << C[i];
            }
        }else{
            vector<int> C = sub(B,A);
            printf("-");
            for(int i=C.size()-1;i>=0;i-- ){
                cout << C[i];
            }
        }


        return 0;
    }

};


#endif //ACWING_HIGHSUB_H
