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
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，

返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，

且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，

但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

*/

class Solution
{
private:
    vector<string> result;
    /*思路：
    第一步：写出分割字符串的回溯函数
    第二步：在函数中，添加检查IP地址合法性的判断代码
    */

    bool check(string str)
    {
        int num = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            num = num * 10 + (str[i] - '0');
        }
        return num <= 255 ? true : false;
    }
    void backtrack(int startIndex, int floor, string &s, string path)
    {
        if (startIndex == s.length() && floor == 4)
        {
            string str = path;
            str.erase(str.length() - 1);
            result.push_back(str);
        }
        if(floor > 4)
        {
            return;
        }
        string strPath;
        for (int i = startIndex; i < s.length() && i < startIndex + 3; ++i)
        {
            strPath += s[i];
            if (strPath.length() == 1 || strPath[0] != '0' && check(strPath))
            {
                backtrack(i + 1, floor + 1, s, path + strPath + ".");
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        backtrack(0,0,s,"");
        return result;
    }
};

