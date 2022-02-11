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
using namespace std;

/* 含有重复元素全排列算法 */
class Solution
{
private:
    vector<vector<int>> ret;
    /*
    含有重复元素的全排列

    先对元素序列进行排序

    排序后，重复的元素会排列在一起

    全排列算法核心——交换元素。对同一层相互重复的元素，不需要交换，跳过


    */
    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void backtrack(int startIndex, vector<int> &nums)
    {
        //终止条件
        if (startIndex == nums.size())
        {
            ret.emplace_back(nums);
            return;
        }
        
        set<int> hsCheck;
        for (int i = startIndex; i < nums.size(); ++i)
        {
            //先处理这一层元素的重复性
            if (!hsCheck.count(nums[i]))
            {
                hsCheck.insert(nums[i]);
                swap(nums, i, startIndex);
                backtrack(startIndex + 1, nums);
                swap(nums, i, startIndex);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        ret.clear();
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
