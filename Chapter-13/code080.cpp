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
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
*/
class Solution
{

private:
    //私有成员变量
    vector<int> subset;
    vector<vector<int>> ret;

    void dfs(int startIndex, int k, int n)
    {
        if (startIndex > n)
        {
            if (subset.size() == k)
            {
                ret.emplace_back(subset);
                return;
            }
            return;
        }
        if (subset.size() == k)
        {
            ret.emplace_back(subset);
            return;
        }

        //放入一个元素
        subset.emplace_back(startIndex);
        dfs(startIndex + 1, k, n);
        subset.pop_back();
        //不放入
        dfs(startIndex + 1, k, n);
    }

    //第二种写法
    void dfs2(int startIndex, int k, int n)
    {
        //终止条件
        if (subset.size() == k)
        {
            ret.emplace_back(subset);
            return;
        }
        if (startIndex > n)
        {
            return;
        }
        //使用for循环
        for (int i = startIndex; i <= n; ++i)
        {
            subset.emplace_back(i);
            dfs2(i + 1, k, n);
            subset.pop_back();
        }
    }

    //在第二种写法的基础上，加上剪枝
    void dfs3(int startIndex, int k, int n)
    {
        //终止条件
        if (subset.size() == k)
        {
            ret.emplace_back(subset);
            return;
        }
        if (startIndex > n)
        {
            return;
        }
        //提前剪枝
        if(subset.size() + (n - startIndex + 1) < k)
        {
            return;
        }
        //使用for循环
        for (int i = startIndex; i <= n; ++i)
        {
            subset.emplace_back(i);
            dfs3(i + 1, k, n);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        subset.clear();
        ret.clear();
        dfs(0, k, n);
        return ret;
    }
};