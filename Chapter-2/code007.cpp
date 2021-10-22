#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    // sort
    sort(nums.begin(), nums.end());
    // two pointer solu
    int sz = nums.size();
    int i = 0;
    while (i < sz - 2)
    {
        int low = i + 1, high = sz - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] + nums[i] == 0)
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                int tmp = nums[low];
                while (low < high && nums[low] == tmp)
                    ++low;
            }
            else
            {
                if (nums[low] + nums[high] + nums[i] < 0)
                    ++low;
                else
                    --high;
            }
        }
        int tmp = nums[i];
        while (i < sz && nums[i] == tmp)
            ++i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> v{-1, 0, 1, 2, -1, -4};
    threeSum(v);

    return 0;
}
