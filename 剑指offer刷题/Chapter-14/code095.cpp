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
这个题在蓝桥杯中做过
状态转移方程切入思路：
字符串s1作横轴，字符串s2作纵轴。从纵轴s2中依次取出字符，和横轴s1中的字符相比较
- 用一个二维数组保存
- 需要对二维数组的第一行进行初始化
- 从纵轴s2中依次取出字符，和横轴s1中的字符相比较
    如果ch1 == ch2
        意味着在s1[0,i-1]和s2[0,j-1]中的公共字符串中多找到了一个公共字符
        dp(i,j) = dp(i-1,j-1) + 1
    如果ch1 ！= ch2
        这两个字符不一样，肯定不会同时出现在一起，此时，有可能的最大公共子序列
        只会存在于s1[0,i-1]和s2[0,j]、s1[0,i]和s2[0,j-1]两者中较多的那个
        dp(i,j) = max (dp(i-1,j), dp(i-1,j-1));
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1));

        /*
        text1 是对应 0~i， text2是对应0~j
        */
        for (int j = 1; j <= len2; ++j)
        {
            for (int i = 1; i <= len1; ++i)
            {
                char ch1 = text1[i - 1];
                char ch2 = text2[j - 1];
                if (ch1 == ch2)
                {
                    dp[j][i] = dp[j - 1][i - 1] + 1;
                }
                else
                {
                    dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
                }
            }
        }
        return dp[len2][len1];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
