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
一般而言，如果一个问题是关于某个实物状态的改变，那么可以考虑转换成图搜索的问题
开密码锁，也即就是密码锁状态从一个状态转换到另一个状态
四个数字组成的密码为一个顶点
一个顶点有8个相邻的顶点
如果顶点的密码状态为0000
响铃顶点为1000,、9000、0100、0900、0010、0090、0001、0009
在搜索的过程中，要避免遇到deadend密码
*/class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> check;
        for (auto &c : deadends)
            check.insert(c);

        queue<string> q;
        unordered_map<string,int> hsMap;
        q.push("0000");
        hsMap["0000"] = 0;
        int ans = -1;
        while (!q.empty())
        {
            string code = q.front();
            q.pop();
            int count = hsMap[code];
            if (code == target)
            {
                ans = count;
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                string newCode1 = code;
                //向前转动
                newCode1[i] = (newCode1[i] + 1 == ':' ? '0' : newCode1[i] + 1);
                if(!check.count(newCode1) && !hsMap.count(newCode1))
                {
                    hsMap[newCode1] = count+1;
                    q.push(newCode1);
                }
                
                //向后转动
                string newCode2 = code;
                newCode2[i] = (newCode2[i] - 1 == '/' ? '9' : newCode2[i] - 1);
                if(!check.count(newCode2) && !hsMap.count(newCode2))
                {
                    hsMap[newCode2] = count+1;
                    q.push(newCode2);
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution test;
    vector<string> dead{"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    test.openLock(dead, target);
    return 0;
}
