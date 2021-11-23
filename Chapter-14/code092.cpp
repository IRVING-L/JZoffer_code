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

class Solution
{
public:
    /*
    终于是理解了这道题的状态转移方程
    1. 定义两个一维数组，f0(i), f1(i)
    2. 就是说f0是将之前的字符串全部变为0，所需要的步骤数；
        f1是将之前的字符串递增字符串以 '1' 结尾时所需要的步骤数
    3.状态转移公式
    f0(i) = f0(i-1) + (s[i]!='0')
    f1(i) = min(f0(i-1), f1(i-1)) + (s[i]!='1')
    解释一下，为什么f1是比较之后取最小值？答：因为f1只是保证前一个字符一定得为1，
    不要求之前的字符全都为1，所以，f1的最小次数，可以从f0从获得
    
    */
    int minFlipsMonoIncr(string s)
    {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        //定义两个一维数组
        vector<int> f0(len);
        vector<int> f1(len);
        //第一个位置需要提前初始化好
        f0[0] = (s[0] == '0' ? 0 : 1);
        f1[0] = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < len; ++i)
        {
            f0[i] = f0[i - 1] + (s[i] == '0' ? 0 : 1);
            f1[i] = min(f1[i - 1], f0[i - 1]) + (s[i] == '0' ? 1 : 0);
        }
        return min(f0.back(), f1.back());
    }
};