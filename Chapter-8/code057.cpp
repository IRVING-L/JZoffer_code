#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<int> myset;
        for(int i=0;i<nums.size();++i)
        {
            //在窗口k中查找第一个大于nums[i]-t的数
            auto iter = myset.lower_bound((long)nums[i] - t);
            if(iter != myset.end() && *iter <= (long)nums[i]+t)
            {
                //找到了
                return true;
            }
            //还没有找到，就把这个数值保存在set容器中
            myset.insert(nums[i]);
            //窗口大小超了k
            if(i>=k)
            {
                myset.erase(nums[i-k]);
            }
        }
        return false;
    }
};