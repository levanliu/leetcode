#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int startRow = 0;
        int startColumn = n-1;
        while(startRow <= m-1 && startColumn >= 0){
            if(matrix[startRow][startColumn] == target){
                return true;
            }else if(matrix[startRow][startColumn] > target){
                startColumn--;
            }else{
                startRow++;
            }
        }
        return false;
    }
};