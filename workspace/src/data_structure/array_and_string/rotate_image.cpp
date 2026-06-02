#include <iostream>
using namespace std;
namespace ns_data_structure_array_and_string_rotate_image {

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix){
        //行交换 + 对角线交换
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m/2;i++){
            swap(matrix[i],matrix[m-i-1]);
        }

        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
} // namespace ns_data_structure_array_and_string_rotate_image
