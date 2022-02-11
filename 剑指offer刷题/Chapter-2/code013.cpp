#include <iostream>
#include <vector>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m > 0)
        {
            int n = matrix[0].size();
            sums.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += matrix[i][j];
                    sums[i + 1][j + 1] = sums[i][j + 1] + sum;
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = sums[row2 + 1][col2 + 1] 
        - sums[row1][col2 + 1] 
        - sums[row2 + 1][col1] 
        + sums[row1][col1];

        return ans;
    }
};
