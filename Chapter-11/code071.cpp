#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
using namespace std;

class Solution
{
private:
    vector<int> preFix;
    int total = 0;

public:
    Solution(vector<int> &w)
    {
        //得到前缀和
        preFix.emplace_back(0);
        for (int i = 0; i < w.size(); ++i)
        {
            total += w[i];
            preFix.emplace_back(total);
        }
    }

    int pickIndex()
    {
        int randNum = rand() % total;
        int low = 1, high = preFix.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (preFix[mid] > randNum)
            {
                if (preFix[mid - 1] <= randNum)
                {
                    //mid对应的区间是第一个大于随机数的
                    return mid - 1;
                }
                high = mid - 1;
            }
            else
            {
                //相等了怎么处理？
                //相等也算是没找到第一个大于他的数，还得继续找
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
