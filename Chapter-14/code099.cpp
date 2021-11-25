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
状态转移方程：
题目讲明：一个机器人每次只能向下或者向右移动一步。
所以所以坐标（i，j）可以从（i-1，j）走过来，也可以从（i，j-1）走过来
dp[i][j]表示当前坐标的路径数字总和
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
初始化dp数组的第一行和第一列的元素，其他元素都由递归公式演算得到
*/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int len1 = grid.size();
        int len2 = grid[0].size();
        vector<vector<unsigned int>> dp(len1, vector<unsigned int>(len2));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < len1; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < len2; ++j)
            dp[0][j] = dp[0][j] + grid[0][j];
        for (int i = 1; i < len1; ++i)
        {
            for (int j = 1; j < len2; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};