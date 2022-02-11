#include <iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int sz = nums.size();
    int ans = sz;
    int front, back;
    front = back = 0;
    int sum = 0;
    for(;back<sz;++back)
    {
        sum+=nums[back];
        while(sum >= target && front<=back)
        {
            int distance = back - front + 1;
            ans = min(ans,distance);
            sum -= nums[front];
            ++front;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> v{2,3,1,2,4,3};
    cout<<minSubArrayLen(7,v);
    return 0;
}
