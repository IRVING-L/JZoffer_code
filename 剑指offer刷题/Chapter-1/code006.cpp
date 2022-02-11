#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
    //解法1，暴力穷举
    // vector<int> ret;
    // int pos1, pos2;
    // int sz = numbers.size();
    // for (pos1 = 0; pos1 < sz - 1; ++pos1)
    // {
    //     pos2 = pos1 + 1;
    //     while (pos2 < sz)
    //     {
    //         if ((numbers[pos1] + numbers[pos2]) == target)
    //         {
    //             ret.push_back(pos1);
    //             ret.push_back(pos2);
    //             return ret;
    //         }
    //         if ((pos1 + pos2) > target)
    //         {
    //             continue;
    //         }
    //         pos2++;
    //     }
    // }
    //return ret;
    //解法2，双指针
    vector<int> ret;
    int lo, hi;
    lo = 0;
    hi = numbers.size() - 1;
    while (lo < hi && numbers[lo] + numbers[hi] != target)
    {
        if (numbers[lo] + numbers[hi] < target)
            lo++;
        if (numbers[lo] + numbers[hi] > target)
            hi--;
    }
    ret.push_back(lo);
    ret.push_back(hi);
    return ret;
    //解法3，二分查找
    // int i = 0;
    // for (; i < numbers.size(); ++i)
    // {
    //     int lo = i + 1, hi = numbers.size() - 1;
    //     while (lo <= hi)
    //     {
    //         int mid = (lo + hi) / 2;
    //         if (numbers[i] + numbers[mid] < target)
    //         {
    //             lo = mid + 1;
    //         }
    //         else if (numbers[i] + numbers[mid] == target)
    //         {
    //             return {i, mid};
    //         }
    //         else
    //         {
    //             hi = mid - 1;
    //         }
    //     }
    // }
    // return {-1, -1};
}
int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 4, 6, 10};
    twoSum(v, 8);
    return 0;
}
