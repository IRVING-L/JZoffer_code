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
private:
    struct TrieNode
    {
        TrieNode *next[2];
        //构造函数
        TrieNode()
        {
            for (int i = 0; i < 2; ++i)
                next[i] = nullptr;
        }
    };
    TrieNode *head;

    void biuldBitTree(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            TrieNode *curr = head;
            int num = nums[i];
            for (int j = 31; j >= 0; --j)
            {
                int bitValue = (num >> j) & 1;
                if (curr->next[bitValue] == nullptr)
                {
                    TrieNode *data = new TrieNode();
                    curr->next[bitValue] = data;
                }
                curr = curr->next[bitValue];
            }
        }
    }
    int findMax(vector<int> &nums)
    {
        int maxValue = INT32_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int ans = 0;
            //让nums中的每一个数，都去字典树中遍历一遍
            TrieNode *curr = head;
            for (int j = 31; j >= 0; --j)
            {
                int bitValue = (num >> j) & 1;
                if (curr->next[1 - bitValue] != nullptr)
                {
                    //存在和num当前位相反的
                    ans = ans | (1 << j);
                    curr = curr->next[1 - bitValue];
                }
                else
                {
                    curr = curr->next[bitValue];
                }
            }
            maxValue = max(maxValue, ans);
        }
        return maxValue;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        head = new TrieNode();
        biuldBitTree(nums);
        return findMax(nums);
    }
};
int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << test.findMaximumXOR(nums);
    cout << (2 | 1) <<endl;
    return 0;
}
