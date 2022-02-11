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
题目：
给定一个字符串 s，请将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的 最少分割次数 。
*/
/*
如何理解这个状态转移方程
1.对第i个位置的字符，从0-i组成的字符串s[0,i]，其最小分割次数，取决于字符串s[0,i]是否为回文字符串
    1.如果是，则分割字数为0；
    2.如果不是。那第i个位置的分割次数，和之前的位置，全都有关系。
        也即，设置一个变量k,从1开始，到i-1结束:
        f(i) = i;
        f(i) = min( f(i), f(k-1)isPal(k,i) + 1)
2.为了能够快速判断一个字符串是否为回文，用一个二维数组保存，空间换时间，让判断的时间复杂度从O(n)降为O(1)
*/
class Solution
{
public:
    int minCut(string s)
    {
        int len = s.length();
        vector<vector<bool>> isPal(len, vector<bool>(len));
        //初始化isPal数组
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                //chI表示0~i组成的字符串的最后一个字符
                char chI = s[i];
                //j遍历0~i组成的字符串，chJ表示其中的字符
                char chJ = s[j];
                if (chI == chJ && i - j <= 1 || isPal[j + 1][i - 1])
                {
                    isPal[j][i] = true;
                }
            }
        }
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                cout << isPal[i][j] << " ";
            }
            cout << endl;
        }
        //dp数组初始化
        vector<int> dp(len);
        for (int i = 0; i < len; ++i)
        {
            if (isPal[0][i])
            {
                //0~i组成的字符串是回文字符串
                dp[i] = 0;
            }
            else
            {
                dp[i] = i;
                for (int j = 1; j < i; ++j)
                {
                    if (isPal[j][i])
                    {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[len-1];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
