#include<iostream>
using namespace std;
    
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i < s.size();i++){
            switch(s[i]){
                case ')':
                    if(st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
                default:
                    st.push(s[i]);
                    break;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};