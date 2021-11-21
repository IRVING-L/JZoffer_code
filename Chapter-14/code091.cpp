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
#include <iostream>
using namespace std;

/*

状态转移方程
第一个房屋肯定选最便宜的那个

第二个房屋，首先是颜色不能和前一个相同，其次从另外两个颜色中选一个最便宜的

color(i-1) = x;
dp[i] = min(cost[i][not_color(i-1)]);

*/
class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        vector<int> red(2);
        vector<int> blue(2);
        vector<int> green(2);
        //初始化
        red[0] = costs[0][0];
        blue[0] = costs[0][1];
        green[0] = costs[0][2];
        if (costs.size() == 1)
        {
            return min(red[0], min(blue[0], green[0]));
        }
        int i = 1;
        for (; i < costs.size(); ++i)
        {
            red[i % 2] = min(blue[(i - 1) % 2], green[(i - 1) % 2]) + costs[i][0];

            blue[i % 2] = min(red[(i - 1) % 2], green[(i - 1) % 2]) + costs[i][1];

            green[i % 2] = min(red[(i - 1) % 2], blue[(i - 1) % 2]) + costs[i][2];
        }
        return min(red[(i - 1) % 2], min(blue[(i - 1) % 2], green[(i - 1) % 2]));
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1, 2, 3}};
    cout << min_element(v[0].begin(), v[0].end()) - v[0].begin();
    return 0;
}
