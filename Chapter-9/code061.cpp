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

/*
给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，
其中第一个元素来自 nums1，
第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

*/
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // 最大堆
        auto cmp = [&](const vector<int> &lhs, const vector<int> &rhs)
        {
            return lhs[0] + lhs[1] < rhs[0] + rhs[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < nums1.size() && i < k; ++i)
        {
            for (int j = 0; j < nums2.size() && j < k; ++j)
            {
                if (heap.size() < k)
                {
                    heap.push({nums1[i], nums2[j]});
                }
                else if (nums1[i] + nums2[j] < heap.top()[0] + heap.top()[1])
                {
                    heap.pop();
                    heap.push({nums1[i], nums2[j]});
                }
            }
        }
        int size = heap.size();
        vector<vector<int>> ret;
        while (size)
        {
            ret.push_back(heap.top());
            heap.pop();
            --size;
        }
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 1, 2};
    vector<int> nums2{1, 3, 4};
    Solution test;
    test.kSmallestPairs(nums1, nums2, 2);
    return 0;
}