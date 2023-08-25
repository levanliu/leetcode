#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int stk[10010];
        int top = -1;
        for(string token:tokens){
            if(token == "+" || token =="-" || token == "*" || token== "/"){  
                int val2 = stk[top--];
                int val1 = stk[top--];
                char opt = token[0];
                switch(opt){
                    case '+':
                        stk[++top] = val1+val2;
                        break;
                    case '-':
                        stk[++top] = val1-val2;
                        break;
                    case '*':
                        stk[++top] = val1*val2;
                        break;
                    case '/':
                        stk[++top] = val1/val2;
                        break;
                }
            }
            else{
                stk[++top] = stoi(token);
            } 
        }
        return stk[top];
    }
};