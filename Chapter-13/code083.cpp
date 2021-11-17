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

/* 全排列算法 */
class Solution
{
private:
    vector<vector<int>> ret;
    vector<int> path;
    //全排列算法
    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void dfs(int startIndex, vector<int> &nums)
    {
        //终止条件
        if(startIndex == nums.size())
        {
            ret.emplace_back(nums);
            return;
        }

        for(int i=startIndex;i<nums.size();++i)
        {
            //交换元素位置
            swap(nums,i,startIndex);
            dfs(startIndex+1,nums);
            swap(nums,i,startIndex);
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        ret.clear();
        dfs(0,nums);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
