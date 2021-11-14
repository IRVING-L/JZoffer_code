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

class Solution
{
private:
    //设置一个“全局变量”用来检查锚点poc的相对位置
    int sz;
    int _k;
    inline int findThePos(vector<int> &nums, int left, int right)
    {
        //随机位置
        int randPos = rand() % (right-left+1) + left;
        swap(nums[randPos],nums[left]);
        int target = nums[left];
        int low = left, high = right + 1;
        while (true)
        {
            while (nums[--high] > target)
                if (high == left)
                    break;
            while (nums[++low] <= target)
                if (low == right)
                    break;
            if (low >= high)
                break;
            swap(nums[low], nums[high]);
        }
        swap(nums[high], nums[left]);
        return high;
    }
    int quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int poc = findThePos(nums, left, right);
            if(sz - poc == _k)
                return nums[poc];
            else if(sz - poc < _k)
            {
                quickSort(nums, left, poc - 1);
            }
            else
            {
                quickSort(nums, poc + 1, right);
            }
        }
        return 0;
    }
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sz = nums.size();
        _k = k;
        int ans = quickSort(nums,0,nums.size() - 1);
        return ans == 0? nums[nums.size() - k] : ans;
    }
};