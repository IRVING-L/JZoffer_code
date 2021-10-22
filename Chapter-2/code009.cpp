#include <iostream>
#include <vector>
using namespace std;



int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int sz = nums.size();
    int ans = 0;
    int front, back;
    front = back = 0;
    int rel = 1;
    for(;back<sz;++back)
    {
        rel *= nums[back];
        while(rel>=k && front <= back)
        {
            
            rel/=nums[front];
            ++front;
        }
        ans = back>=front?back-front+1:0;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
