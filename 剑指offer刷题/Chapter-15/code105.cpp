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

class Solution
{
    /**
     * 这道题在蓝桥杯是做过的：
     * 解题思路：DFS搜索
     * 在二维数组表示的grid地图中，对于当前坐标位置grid[i][j]，
     * 可以朝上下左右四个方向搜索
     * 搜索过的位置，把grid[i][j]的值置为0，并且不会恢复
    */
private:
    int row;    //行数
    int col;    //列数
    int count;  //每一个岛屿的面积计数
    int result; //返回的答案
    //dfs搜索函数
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        //标记当前位置
        grid[x][y] = 0;
        //增加岛屿面积
        count++;
        //上下左右四个方向的搜索
        if (x + 1 < row && grid[x + 1][y])
            dfs(grid, x + 1, y);
        if (x - 1 >= 0 && grid[x - 1][y])
            dfs(grid, x - 1, y);
        if (y + 1 < col && grid[x][y + 1])
            dfs(grid, x, y + 1);
        if (y - 1 >= 0 && grid[x][y - 1])
            dfs(grid, x, y - 1);
    }
    int helper(vector<vector<int>> &grid)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j])
                {
                    //每次搜索前将count清0
                    count = 0;
                    dfs(grid, i, j);
                    //搜索完成后，更新结果
                    result = max(result, count);
                }
            }
        }
        return result;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        result = 0;
        return helper(grid);
    }
};