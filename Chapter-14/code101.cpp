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
非常经典的01背包问题
01背包问题，选或者不选一个元素，放入背包，使得能够满足背包里的东西xx最大的条件
这道题就是典型的01背包
可以选择的物品为：数组元素
背包容量：数组和
1.二维数组dp[i][j]表示什么含义？
   从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和 是否等于 j
2.dp[i][j]由前面的哪些状态推导而来？
    不放dp[i][j]: 看dp[i-1][j]的状态
    放dp[i][j]:看dp[i-1][j-nums[i]的状态
    也即：
    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
3.如何初始化这个二维数组的第一行和第一列？
行号表示可以选择的物品，列号为背包的容量
第一行表示用第一个物品，能否填满背包容量j
第一列表示用【0，i】的物品，能否填满背包容量为0的背包

*/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int halfSum = 0;
        for (int num : nums)
            halfSum += num;
        if (halfSum % 2) //奇数就不用看了，不可能的
            return false;
        halfSum /= 2;

        //halfSum表示背包的最大值
        vector<vector<bool>> dp(nums.size(), vector<bool>(halfSum + 1));
        //初始化第一行和第一列
        for (int i = 0; i < nums.size(); ++i)
            dp[i][0] = 1;
        //第一行
        for (int j = 1; j <= halfSum; ++j)
            dp[0][j] = (nums[0] == j);

        //由状态转移方程 演算其他元素
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 1; j <= halfSum; ++j)
            {
                bool state1 = dp[i - 1][j];
                bool state2 = ((j - nums[i]) >= 0 ? dp[i - 1][j - nums[i]] : 0);
                dp[i][j] = state1 || state2;
            }
        }
        //处理结果
        return dp[nums.size() - 1][halfSum];
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
