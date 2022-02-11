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
    int singleNonDuplicate(vector<int> &nums)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid])
            {
                if (halvesAreEven)
                {
                    //右半部分有那个单独的
                    lo = mid + 2;
                }
                else
                {
                    //右半部分没有那个单独的
                    hi = mid - 1;
                }
            }
            else if (nums[mid - 1] == nums[mid])
            {
                if (halvesAreEven)
                {
                    //右半部分没有那个单独的
                    hi = mid - 2;
                }
                else
                {
                    //右半部分有那个单独的
                    lo = mid + 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    test.singleNonDuplicate(nums);
    return 0;
}
