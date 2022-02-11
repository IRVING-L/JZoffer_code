#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

/*
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。

不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
*/


//记忆化深搜
class Solution
{
private:
    vector<vector<int>> memo;
    const vector<vector<int>> dirc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>> &matrix, int i, int j)
    {
        if (memo[i][j] == 0)
        {
            //(i,j)还没被访问过，假设该位置最差情况，没有任何路能走通
            memo[i][j] = 1;
            //探索四个方向
            for (int k = 0; k < 4; ++k)
            {
                int ni = i + dirc[k][0];
                int nj = j + dirc[k][1];
                if (ni < matrix.size() && ni >= 0 && nj < matrix[0].size() && nj >= 0 && matrix[ni][nj] > matrix[i][j])
                {
                    //既然当前位置（i，j）还有相邻顶点，那么不管dfs()的返回值是多少，都要把当前位置算进去
                    memo[i][j] = max(memo[i][j], dfs(matrix, ni, nj) + 1);
                }
            }
        }
        return memo[i][j];
    }
    int helper(vector<vector<int>> &matrix)
    {
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                result = max(result, dfs(matrix, i, j));
            }
        }
        return result;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        memo.resize(matrix.size(), vector<int>(matrix[0].size()));
        return helper(matrix);
    }
};
