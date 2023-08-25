//
// Created by le on 2022/12/19.
//

#ifndef MAIN_BFSSEARCH_H
#define MAIN_BFSSEARCH_H

#include<iostream>
#include <cstring>
#include "algorithm"
#include "queue"
using namespace  std;
typedef pair<int,int> PII;

class bfsSearch {
private:
    static const int N = 10;
    int n,m;
    int g[N][N];  //graph
    int d[N][N];  //distance
    PII q[N*N];   //x,y
public:
    int bfs(){
        int hh=0,tt=0;
        q[0] ={0,0};
        memset(d,-1,sizeof d);
        d[0][0] =0;
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        while(hh<=tt){
            auto t=q[hh++];
            for(int i=0;i<4;i++){
                int x= t.first + dx[i],y=t.second+dy[i];  //neighbor
                if(x>=0 && x<n && y>=0 && y<=m && g[x][y]==0 && d[x][y]==-1){
                    d[x][y] =d[t.first][t.second]+1;
                    q[++tt]={x,y};
                }
            }
        }
        return d[n-1][m-1];
    }
    int bfsMain(){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> g[i][j];
            }
        }
        cout << bfs() << endl;
        return 0;
    }
};


#endif //MAIN_BFSSEARCH_H
