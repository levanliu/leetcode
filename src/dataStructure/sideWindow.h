

#include <cstdio>
#include<iostream>

const int N = 1000010;

int n;

int a[N],q[N];


int main()
{
    int n,k;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int hh=0,tt=-1;

    for(int i=0;i<n;i++){
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh<tt && a[q[tt]] >=a[i]) tt--;

        q[++tt] = i;
        if(i>=k-1) printf("%d",q[q[hh]]);
    }
    
    hh=0,tt=-1;

    for(int i=0;i<n;i++){
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh<tt && a[q[tt]] <=a[i]) tt--;

        q[++tt] = i;
        if(i>=k-1) printf("%d",q[q[hh]]);
}

}
