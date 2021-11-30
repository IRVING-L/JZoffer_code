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

class Solution
{
private:
    int result = 0;
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>> &matrix, int i, int j, int sum)
    {
        vis[i][j] = true;
        bool isEnd = true;
        //四个方向
        if (i + 1 < matrix.size() && !vis[i + 1][j] && matrix[i + 1][j] > matrix[i][j])
        {
            isEnd = false;
            dfs(matrix, i + 1, j, sum + 1);
        }
        if (i - 1 >= 0 && !vis[i - 1][j] && matrix[i - 1][j] > matrix[i][j])
        {
            isEnd = false;
            dfs(matrix, i - 1, j, sum + 1);
        }
        if (j + 1 < matrix[0].size() && !vis[i][j + 1] && matrix[i][j + 1] > matrix[i][j])
        {
            isEnd = false;
            dfs(matrix, i, j + 1, sum + 1);
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && matrix[i][j - 1] > matrix[i][j])
        {
            isEnd = false;
            dfs(matrix, i, j - 1, sum + 1);
        }
        vis[i][j] = false;
        if (isEnd)
        {
            result = max(result, sum);
        }
    }
    //四个方向的辅助数组
    const vector<vector<int>> dirc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> path;
    void bfs(vector<vector<int>> &matrix, int i, int j)
    {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        path[i][j] = 1;
        int sum = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            sum = max(sum, path[x][y]);
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dirc[i][0];
                int ny = y + dirc[i][1];
                if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size()
                 && matrix[nx][ny] > matrix[x][y])
                {
                    q.emplace(nx, ny);
                    path[nx][ny] = path[x][y] + 1;
                }
            }
        }
        result = max(sum, result);
    }
    void helper(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                //dfs(matrix, i, j, 1);
                bfs(matrix, i, j);
            }
        }
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        vis.resize(matrix.size(), vector<bool>(matrix[0].size()));
        path.resize(matrix.size(), vector<int>(matrix[0].size()));
        helper(matrix);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    test.longestIncreasingPath(matrix);
    return 0;
}
