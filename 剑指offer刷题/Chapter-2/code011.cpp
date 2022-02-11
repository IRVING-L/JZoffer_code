#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    //暴力穷举 O(n^2)
    // int ans = 0;
    // int len = nums.size();
    // int sum = 0;
    // for(int i=0;i<len;++i)
    // {
    //     for(int j=i;j>=0;--j)
    //     {
    //         sum+=nums[j];
    //         if((i-j+1)%2==0 && sum%2==0 && sum)
    //             ans = max(i-j+1,ans);
    //     }
    // }
    // return ans;
    int ans = 0;
    int len = nums.size();
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < len; ++i)
    {
        sum += nums[i] == 0 ? -1 : 1;
        if (mp.find(sum - 0) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
            mp[sum] = i;
    }
    return ans;
}

int main()
{
    vector<int> v{0, 0, 1, 1, 1, 0, 0, 0, 1};
    cout << findMaxLength(v);
    return 0;
}