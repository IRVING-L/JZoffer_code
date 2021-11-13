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
class Solution
{
private:
    vector<vector<int>> Map;

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //第一步：写一个lambda表示式，用来sort比较容器元素大小
        auto cmp = [](const vector<int> &rhs, const vector<int> &lhs)
        {
            return rhs[0] < lhs[0];
        };
        //排序的时间复杂度是O(nlogn)
        sort(intervals.begin(), intervals.end(), cmp);
        //第二步：遍历intervals，比较相邻两个区间是否有重合
        //首先是检查前一个区间的终止时间是否大于后一个区间的起始时间
        //如果大于，那么更新后一个区间的起始时间和终止时间
        //这段处理数据的代码，时间复杂度是O(n)，right和left指针一直在往前走
        int left = 0;
        for (int right = 1; right < intervals.size(); ++right)
        {
            if (intervals[left][1] >= intervals[right][0])
            {
                //有时间上的重合
                intervals[right][0] = intervals[left][0];
                intervals[right][1] = max(intervals[right][1],intervals[left][1]);
                intervals[left][0] = -1;
            }
            //没有时间上的重合，left向前移动
            left = right;
        }
        //第三步：处理结果
        vector<vector<int>> ret;
        for(int i=0;i<intervals.size();++i)
        {
            if(intervals[i][0]!=-1)
            {
                //如果intervals中的元素，第一个元素没有被置零的，那就是有效的
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};