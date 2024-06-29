
//
// Created by le on 18/10/2022.
//

#ifndef CPP_REMOVETRAILINGZEROS_H
#define CPP_REMOVETRAILINGZEROS_H

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;


class solution{
public:
	string removeTrailingZeros(string num){
		int n = num.size();
		if(n < 1){
			return num;
		}
		if(n == 1){
			if(num[0] != '0'){
				return num;
			}else{
				return "";
			}
		}
		int i = n-1;
		for(;i>=0;){
			if(num[i] == '0'){
				i--;
			}else{
				break;
			}
		}
		return num.substr(0,i+1);
	}
};

#endif
