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
给定一个字符串 s ，请将 s 分割成一些子串，

使每个子串都是 回文串 ，返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。
*/
class Solution
{
private:
    //私有成员
    vector<vector<string>> result;
    vector<string> path;
    bool check(string str)
    {
        int left = 0, right = str.length() - 1;
        while (left <= right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack(int startIndex, string &s)
    {
        //终止条件
        if (startIndex == s.length())
        {
            //startIndex 指针，表示当前读取的字符串位置
            //应该是要一个子字符串
            result.push_back(path);
            return;
        }
        //for循环
        string substr;
        for (int i = startIndex; i < s.length(); ++i)
        {
            //在这一层所做的事情，就是收集字符串
            substr += s[i];
            if (check(substr))
            {
                path.push_back(substr);
                //下一层
                backtrack(i + 1, s);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backtrack(0, s);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
