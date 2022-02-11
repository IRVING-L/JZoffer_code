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
尝试着用自己的话复述一遍 状态转移方程 的推导过程
第一步：假设建立
拿到这个题，用s1和s2交织出s3，人的大脑很容易想到这个过程：
    对于s3的每一个字符，我都可以从s1或者s2中选择。
    解决一个问题需要多个步骤，每个步骤有多个选择，这是典型的回溯法
但其实从s3这个角度出发，脑子中模拟这个取数的过程就很复杂了，显然是很麻烦的
那么如何建立dp解决方法的假设呢？
- 拿到这个题，有两个字符串，肯定是要用二维数组模拟这个过程了，那么二维数组dp(i,j)的意义是何？
- 《剑指》书中给出的假设建立是：
    dp(i,j)表示s1(0，i) 和s2(0,j)能否交织成 s3(0,i+j+1)
- dp(i,j)如何推导
    1.若s1[i] == s3[i+j+1]，dp(i,j) = dp(i-1,j)
    2.若s2[j] == s3[i+j+1], dp(i,j) = dp(i,j-1)
    3.若若s1[i] == s2[j] == s3[i+j+1], dp(i,j) = dp(i-1,j) || dp(i,j-1)
    4.若都不想等，那dp(i,j) = false;

    同时，需要对第一行和第一列进行初始化：
    二维数组首元素表示s1[] 、s2[] 能否交织成s3[]
    第一行元素表示，s1[,i]和s3[,i]的交织关系
    第一列元素表示，s2[,j]和s3[,j]的交织关系
*/
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3)
            return false;
        vector<vector<bool>> dp(len2 + 1, vector<bool>(len1 + 1));
        //对第一行和第一列进行初始化：
        dp[0][0] = true;
        //对第一行
        for (int i = 0; i < len1; ++i)
        {
            dp[0][i + 1] = ((s1[i] == s3[i]) && dp[0][i]);
        }
        //对第一列
        for (int j = 0; j < len2; ++j)
        {
            dp[j + 1][0] = ((s2[j] == s3[j]) && dp[j][0]);
        }
        //对剩余的元素
        for (int j = 1; j <= len2; ++j)
        {
            for (int i = 1; i <= len1; ++i)
            {
                char ch1 = s1[i - 1];
                char ch2 = s2[j - 1];
                char ch3 = s3[i + j - 1];
                if(ch1 == ch2)
                {
                    if(ch1 == ch3)
                        dp[j][i] = dp[j][i-1] || dp[j-1][i];
                    else
                        dp[j][i]  = false;
                }
                else
                {
                    if(ch1 == ch3)
                        dp[j][i] = dp[j][i-1];
                    else if(ch2 == ch3)
                        dp[j][i] = dp[j-1][i];
                    else
                        dp[j][i]  = false;
                }
            }
        }
        return dp[len2][len1];
    }
};