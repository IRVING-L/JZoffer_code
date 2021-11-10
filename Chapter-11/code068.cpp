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
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] < target)
            {
                low = mid+1;
                continue;
            }
            else if(nums[mid] == target)
            {
                return mid;
            }
            else
            {
                high = mid-1;
                continue;
            }
        }
        return low;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
