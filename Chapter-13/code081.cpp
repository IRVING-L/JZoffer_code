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
给定一个无重复元素的正整数数组 candidates 和一个正整数 target 
找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。
如果至少一个所选数字数量不同，则两种组合是唯一的。 

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。

*/

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<int> flag;
    set<vector<int>> check;
    void dfs(int target, int sum, vector<int> &candidates)
    {
        //终止条件
        if (sum == target)
        {
            //用并查集检查一下
            if (check.find(flag) == check.end())
            {
                result.emplace_back(path);
                check.insert(flag);
            }
            return;
        }
        //剪枝
        if (sum > target)
        {
            return;
        }
        //在当前层所做的事情
        for (int i = 0; i < candidates.size(); ++i)
        {
            path.emplace_back(candidates[i]);
            flag[candidates[i]]++;
            dfs(target, sum + candidates[i], candidates);
            path.pop_back();
            flag[candidates[i]]--;
        }
    }

    //解法2，一点点小修改
    void dfs2(int startIndex, int target, int sum, vector<int> &candidates)
    {
        //终止条件
        if (sum == target)
        {
            //用并查集检查一下
            if (check.find(flag) == check.end())
            {
                result.emplace_back(path);
                check.insert(flag);
            }
            return;
        }
        //剪枝
        if (sum > target)
        {
            return;
        }
        //在当前层所做的事情
        for (int i = startIndex; i < candidates.size(); ++i)
        {
            path.emplace_back(candidates[i]);
            dfs2(i, target, sum + candidates[i], candidates);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        result.clear();
        path.clear();
        flag.resize(200);
        dfs(target, 0, candidates);
        return result;
    }
};