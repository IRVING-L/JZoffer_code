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

/**
 * 这道题的思路也是一样的，需要注意的是
 * dp[i][j]的推导公式，以及最后结果的处理
 * 可以将等边三角形转想成直角边三角形
 * （i，j）只能由（i-1，j-1）和（i-1，j）走过来
 * 那么dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
 * 如何初始化？只需要初始化好二维数组的第一列元素就可，数组的上半三角用不到
 * 如何处理结果？二维数组的最后一行元素的最小值
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len1 = triangle.size();
        int len2 = triangle.back().size();
        vector<vector<long long>> dp(len1, vector<long long>(len2, INT32_MAX));
        //初始化第一列元素
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len1; ++i)
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
        //由状态转移方程演算其他元素
        for (int i = 1; i < len1; ++i)
        {
            for (int j = 1; j < triangle[i].size(); ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
        //处理最后一行的元素
        int ans = INT32_MAX;
        for (int i = 0; i < len2; ++i)
        {
            ans = (ans > dp[len1 - 1][i] ? dp[len1 - 1][i] : ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<vector<int>> v{{-10}};
    test.minimumTotal(v);
    return 0;
}
