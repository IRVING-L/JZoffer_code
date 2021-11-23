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
谈谈我自己对这个题的理解：（对状态转移方程的理解）
1.要想组成feibo，至少三个数，A[i] = A[j] + A[k]（i > j > k)
2.就是说，i之前的序列中，可能是不止有一串feibo能和A[i]组成更长的
3.这就意味着，我们需要去记录，在i之前，有多少种能够形成feibo序列的可能
4.记录的方式，是采用坐标(i,j) = 长度。我们可以用一个二维数组来记录
5.数组更新计算的方法：f(i, j) = f(j, k) + 1 <--- A[i] = A[j] + A[k]（i > j > k)
*/
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int len = arr.size();
        vector<vector<int>> dp(len, vector<int>(len));
        //用一个哈希表保存数字，
        unordered_map<int, int> hsMap;
        for (int i = 0; i < len; ++i)
        {
            hsMap[arr[i]] = i;
        }
        int result = 2;
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int Ak = arr[i] - arr[j];
                int k = hsMap.count(Ak) ? hsMap[Ak] : INT32_MAX;
                if (k < j)
                {
                    //由于arr中的数是单调递增的,如果哈希表中存在Ak，这个Ak一定是在Ai之前的
                    //此外，在if判断条件中，保证Ak一定是小于Aj的元素
                    dp[i][j] = dp[j][k] + 1;
                }
                else
                {
                    dp[i][j] = 2;
                }
                //更新一下最大值
                result = max(result, dp[i][j]);
                //把dp数组打印出来
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return result > 2 ? result : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
    test.lenLongestFibSubseq(arr);
    return 0;
}
