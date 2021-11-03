/*
给定一个整数数组 nums 和一个整数 k ，
请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;
class Solution
{
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> occurrences;
        for (auto &v : nums)
        {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> q;
        for (auto &data : occurrences)
        {
            if (q.size() == k)
            {
                if (q.top().second < data.second)
                {
                    q.pop();
                    q.emplace(data);
                }
            }
            else
            {
                q.emplace(data);
            }
        }
        vector<int> ret;
        while (!q.empty())
        {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
