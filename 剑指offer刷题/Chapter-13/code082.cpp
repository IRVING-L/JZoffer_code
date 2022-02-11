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
给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，

找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。 

*/

class Solution
{
private:
    vector<vector<int>> ret;
    vector<int> path;
    /*
    解题思路和前面的题一样的，也是基于递归深搜的回溯算法

    不同的点在于，放弃某个元素放入集合中时，要把重复的该元素都放弃了

    因此，在使用这个集合时，要对该集合排序

    排序在回溯算法中，也算是经常出现的一个套路 
    */
    void dfs(int startIndex, int target, vector<int> &candidates)
    {
        //终止条件
        if (target == 0)
        {
            ret.emplace_back(path);
            return;
        }
        //不放入该元素
        //跳过所有重复的元素
        if (target > 0 && startIndex < candidates.size())
        {
            int reg = startIndex;
            while (reg < candidates.size() &&
                   candidates[reg] == candidates[startIndex])
            {
                reg++;
            }
            dfs(reg, target, candidates);

            //放入该元素
            path.emplace_back(candidates[startIndex]);
            dfs(startIndex + 1, target - candidates[startIndex], candidates);
            path.pop_back();
        }
    }

    //写法2，能不能改成for循环？
    void dfs2(int startIndex, int target, vector<int> &candidates)
    {
        //终止条件
        if (target == 0)
        {
            ret.emplace_back(path);
            return;
        }
        //for循环开始
        /* 
        for循环 和 分支写法的区别在哪？
        或者说，for循环是如何实现，取元素 和 不取元素的？
        答：递归函数进入下一层后，在下一层中，startIndex已经+1了，之前的那个数就取不了了（这个控制重复取）
        通过for循环中指针 i 的移动，来控制取或者不取该元素
        取或者不取，都得是在 一层的逻辑中完成的，所以删除重复元素，应该在递归代码之前
        */
        if (target > 0 && startIndex < candidates.size())
        {
            for (int i = startIndex; i < candidates.size(); ++i)
            {
                //在每一层，咱们只取不同的元素
                if (i > startIndex && candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                path.emplace_back(candidates[i]);
                //进入下一层，咱这一层不管
                dfs(i + 1, target - candidates[i], candidates);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        ret.clear();
        path.clear();
        dfs(0, target, candidates);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> nums{2, 5, 1, 2, 2};
    test.combinationSum2(nums, 5);
    return 0;
}
