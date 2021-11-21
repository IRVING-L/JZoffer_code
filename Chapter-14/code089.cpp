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
using namespace std;

/*

一个专业的小偷，计划偷窃沿街的房屋, 每间房内都藏有一定的现金，

影响小偷偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，

如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组 nums ，

请计算 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

*/

/*

状态转移方程：

dp[i] = max(dp[i-2]+nums[i], dp[i-1]);

dp[i] 的含义：在第i个位置，所能偷到的最大的财产，最大请注意

到了第i个位置，就有两个选择

偷第i个房屋，那么意味着i-1处是不能动的了，此时就是dp[i-2]+nums[i]
不偷第i个房屋，那么可以选择偷i-1的房屋，注意是选择
比较两者的大小
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        if (nums.size() == 1)
        {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        //继续初始化dp数组
        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        //返回何值
        return dp[dp.size() - 1];
    }
};
