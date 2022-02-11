#include <iostream>
#include <vector>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    // vector<int> ST;
    // int len = nums.size();
    // int sum = 0;
    // for (int i = 0; i < len; ++i)
    // {
    //     sum += nums[i];
    //     ST.push_back(sum);
    // }
    // int ans = len;
    // for (int j = len - 1; j >= 0; --j)
    // {
    //     int left = (j==0? 0 : ST[j-1]);
    //     int right = (j == len-1?0:ST[len-1]-ST[j]);
    //     if(left == right)
    //         ans = min(ans, j);
    // }
    // return ans;

    int len = nums.size();
    int total = 0;
    for(int i=0;i<len;++i)
    {
        total += nums[i];
    }
    int ans = len;
    int sum = 0;
    for(int j=0;j<len;++j)
    {
        sum+=nums[j];
        int left = sum - nums[j];
        int right = total - sum;
        if(left == right)
            return j;
    }
    return -1;
}

int main()
{
    return 0;
}