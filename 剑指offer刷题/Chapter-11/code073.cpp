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
    int getHours(vector<int> &piles, int speed)
    {
        int h = 0;
        for (auto &num : piles)
        {
            h += (num - 1) / speed + 1;
        }
        return h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxNum = INT32_MIN;
        for (auto &num : piles)
        {
            maxNum = max(maxNum, num);
        }
        int left = 1;
        int right = maxNum;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int cost = getHours(piles, mid);
            if (cost > h)
            {
                left = mid + 1;
            }
            else
            {
                //为什么要要在小于等于这里增加判断
                //cost<=h 意味着吃的速度太快了，花费的时间少了，下一步就要缩小到左半区间了
                //由于下次区间是右半边是mid - 1，那么问题就来了
                //如果mid此时就是最合适的速度，那不就错过了吗
                //相反
                //当mid速度小导致花费时间长于h，这个mid肯定是不合适的
                if (mid==1 || getHours(piles, mid - 1) > h)
                {
                    return mid;
                }
                right = mid - 1;
            }
        }
        return -1;
    }
};