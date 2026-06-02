#include <iostream>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool colZeros = false;
        bool rowZeros = false;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                rowZeros = true;
            }
        }
        for (size_t i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                colZeros = true;
            }
        }

        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (size_t i = 1; i < matrix.size(); i++)
        {
            for (size_t j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (rowZeros)
        {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }

        if (colZeros)
        {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};