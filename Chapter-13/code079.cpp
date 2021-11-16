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
给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

class Solution
{
private:
    //回溯算法
    //全局变量
    vector<int> subset;
    vector<vector<int>> results;
    //剑指offer的写法
    // void backTracking(vector<int> &nums, int startIndex)
    // {
    //     //终止条件，退出递归
    //     if(startIndex >= nums.size())
    //     {
    //         results.emplace_back(subset);
    //         return;
    //     }
    //     //操作元素
    //     //不放入任何元素
    //     backTracking(nums,startIndex+1);
    //     //取startindex对应的元素放入
    //     subset.emplace_back(nums[startIndex]);
    //     backTracking(nums,startIndex+1);
    //     subset.pop_back();

    // }

    //代码随想录的写法
    void backTracking(vector<int> &nums, int startIndex)
    {
        results.push_back(subset); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size())
        { // 终止条件可以不加
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backTracking(nums, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        subset.clear();
        results.clear();
        backTracking(nums, 0);
        return results;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
