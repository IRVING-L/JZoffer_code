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
还是尝试用自己的话重复一遍**状态转移方程** 的推导

首先，这个题的求解需要多个步骤，一个步骤面临多个选择，可以用回溯法，
但是这题不求包含的序列的下标啊什么的，只求包含的次数，所以用动规

这道题有两个序列，我首先反应，一个一维数组能不能解决这个问题，显然不能
那就使用一个二维数组。二维数组的假设创建了，需要回答这几个问题：
1.二维数组dp[i][j]表示什么含义？
2.dp[i][j]由前面的哪些状态推导而来？
3.如何初始化这个二维数组的第一行和第一列？

现在说一下《剑指》书上对这些问题的回答：
1.dp[i][j]表示，字符串S[0,i]包含T[0,j]的次数，所以说二维数组的右下角最后一个元素的值就是问题的答案
2.将S[i]同T[j]这两个字符相比较，比较有两个结果：
    a.S[i]==T[j]，两字符相同（这里是重点，很多人都想不到）
        1.算上S[i]和T[j]，dp[i][j] = dp[i-1][j-1]（这里其实有点难理解）
        2.舍弃S[i]，dp[i][j] = dp[i-1][j]
        所以说，当S[i]=T[j]时，dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    b.S[i]！=T[j]，两字符不相同，dp[i][j] = dp[i-1][j]
    当字符不相同时，很好理解，公式推导也是顺其自然的。
    问题是，当两字符相等时，这里的状态转移方程，令人感到疑惑。（你能看懂，但是自己独立去做
    肯定不会像书上那样去构建等式）
3.同96题字符串交织，二维数组的第一行表示，S空字符串和T[0,j]的包含关系
第一列表示S[0,i]和T空的包含关系。很容易初始化好
*/
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        if (s.size() < t.size())
        {
            return 0;
        }

        vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < s.size(); ++i)
        {
            dp[i + 1][0] = 1;
            for (int j = 0; j <= i && j < t.size(); ++j)
            {
                dp[i + 1][j + 1] = (s[i] == t[j]) ? dp[i][j] + dp[i][j + 1] : dp[i][j + 1];
            }
        }
        return dp[s.size()][t.size()];
    }
};
