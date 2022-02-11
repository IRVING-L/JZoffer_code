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

一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，

每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，

这意味着第一个房屋和最后一个房屋是紧挨着的。

同时，相邻的房屋装有相互连通的防盗系统，

如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组 nums ，

请计算 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

*/

class Solution
{
private:
    int biuldDP(vector<int> &nums, vector<int> &dp, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        if (left > right)
        {
            return INT32_MIN;
        }
        //前两个元素都是直接赋值
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i <= right; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[right];
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        int max_1 = biuldDP(nums, dp, 0, nums.size() - 2);
        int max_2 = biuldDP(nums, dp, 1, nums.size() - 1);
        return max(max_1, max_2);
    }
};
