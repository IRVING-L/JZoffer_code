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
完全背包问题
完全背包和01背包的区别在于，完全背包中，一个元素可以使用无限次

既然和01背包只有那一点区别，在解题上还是需要用到二维数组
1.dp[i][j]的含义
    序列[0,i]选取元素使其金币总额等于j的最小硬币个数
2.1.dp[i][j]的推导
    对于第i个元素，我们有以下选择：
    不放入该元素
        dp[i][j] = dp[i-1][j];
    放入k个i元素
        dp[i][j] = dp[i-1][j-k*coins[i]] + k;
    所以
        dp[i][j] = min(dp[i-1][j-k*coins[i]]+k);
3.如何初始化
    第一行是用第一颗硬币凑出各种数额，可以直接初始化
    后面的元素用状态转移方程演算推导
*/
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, INT32_MAX));
        //初始化第一列
        for(int i=0;i<coins.size();++i)
            dp[i][0] = 0;
        //演算其他元素
        for(int i=0;i<coins.size();++i)
        {
            for(int j=coins[i];j<=amount;++j)
            {
                if(dp[i][j-coins[i]] != INT32_MAX)
                {
                    dp[i][j] = min(dp[i][j-coins[i]] + 1, dp[i][j]);
                }
            }
        }
        //处理结果
        return (dp[coins.size()-1][amount]==INT32_MAX?-1:dp[coins.size()-1][amount]);
    }
};
int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> coins{1, 2, 5};
    test.coinChange(coins, 11);
    return 0;
}
