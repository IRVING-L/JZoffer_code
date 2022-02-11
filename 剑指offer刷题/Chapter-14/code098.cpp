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
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

*/
//回溯法就可以做。时间复杂度O(mn)？

//尝试用动规做
/*
状态转移方程的推导：
这道题是二维平面的矩阵路径和，dp数组肯定是二维的
1.二维数组dp[i][j]表示什么含义？
    走到坐标（i，j）的路径和数，所以问题的答案就是二维数组的最后一个元素
2.dp[i][j]由前面的哪些状态推导而来？
    图上说了，只能向下或者向右走，所以坐标（i，j）可以从（i-1，j）走过来，
    也可以从（i，j-1）走过来，因此
    dp[i][j]=dp[i-1][j]+dp[i][j-1];
3.如何初始化这个二维数组的第一行和第一列？
    将二维数组扩宽半圈，dp[1][1] = 1，其他元素都由递归公式演算得到
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
