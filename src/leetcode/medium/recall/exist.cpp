#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int r,int c){
        if(i == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        if( r<0 || r>m-1 || c<0 || c>n-1 || word[i] != board[r][c] ||  board[r][c] == '.'){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '.';
        bool ans = false;
         ans |= dfs(board,word,i+1,r+1,c) ;
         ans |= dfs(board,word,i+1,r,c+1) ;
         ans |= dfs(board,word,i+1,r-1,c) ;
         ans |= dfs(board,word,i+1,r,c-1) ;
        
        board[r][c] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,0,i,j))
                    return true;
            }
        }

        return false;
    }
};