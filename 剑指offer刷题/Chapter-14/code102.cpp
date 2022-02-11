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
理一下这道题的逻辑
对于该题，有多个步骤（多个元素—），每个步骤（元素）都有两种选择
让其变为正数或者变为负数，最后得到其总和。这看似是一个回溯
但是不要求我们写出具体的表达式，只用求能够满足题意的数目，这题适合用dp

dp[i][j]的含义：从[0,i]中取出的数，表达式和等于j的次数
如何推导：
    对于dp[i][j]，也就是对于nums[i]，有两种选择：
    放入+nums[i]:
        dp[i][j] = dp[i-1][j-nums[i]]
    放入-nums[i]
        dp[i][j] = dp[i-1][j+nums[i]]
    合在一起就是：
        dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]]
如何初始化？
    1.dp数组中j的大小范围？
        从状态转移公式我们可以看到，j的范围应该是在[-sum, sum]
        所以dp的创建应该是这样的：
        vector<vector<int>> dp(nums.size(), vector<int>(2*sum+1));
    2.可以预先初始化好哪些元素？
        也是从表达式来，有一个i-1，那必然是要提前初始化第一行
        其他都是默认的0
*/
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (target > sum || target < -sum)
            return 0;
        vector<vector<unsigned int>> dp(nums.size(), vector<unsigned int>(2 * sum + 1));
        for (int i = -sum; i <= sum; ++i)
        {
            dp[0][i + sum] = (nums[0] == i) + (-nums[0] == i);
        }
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = -sum; j <= sum; ++j)
            {
                int state1 = (j + nums[i] + sum <= 2 * sum ? dp[i - 1][j + nums[i] + sum] : 0);
                int state2 = (j - nums[i] + sum >= 0 ? dp[i - 1][j - nums[i] + sum] : 0);
                dp[i][j + sum] = state1 + state2;
            }
        }
        return dp[nums.size() - 1][target + sum];
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> nums{0, 0, 0, 0, 0, 0, 0, 0, 1};
    test.findTargetSumWays(nums, 1);
    return 0;
}
