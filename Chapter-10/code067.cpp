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
        bool val;
        TrieNode *next[2];
        //构造函数
        TrieNode() {}
        TrieNode(bool x)
        {
            val = x;
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
            for (int j =31; j >= 0; --j)
            {
                bool bitValue = (num >> j) & 1;
                if (curr->next[bitValue] == nullptr)
                {
                    TrieNode *data = new TrieNode(bitValue);
                    curr->next[bitValue] = data;
                }
                curr = curr->next[bitValue];
            }
        }
    }
    void findMax(int &num)
    {
        TrieNode *curr = head;
        queue<TrieNode *> q;
        for (int i = 0; i < 2; ++i)
        {
            if (curr->next[i] != nullptr)
                q.push(curr->next[i]);
        }
        while (!q.empty())
        {
            num = num << 1;
            int sz = q.size();
            bool flag = q.front()->val;
            int carry = 0;
            for (int i = 0; i < sz; ++i)
            {
                TrieNode *data = q.front();
                q.pop();
                if (!carry && flag != data->val)
                    carry = 1;
                
                if (data->next[0] != nullptr)
                    q.push(data->next[0]);
                if (data->next[1] != nullptr)
                    q.push(data->next[1]);
                
            }
            num += carry;
        }
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        head = new TrieNode(false);
        biuldBitTree(nums);
        int ret = 0;
        findMax(ret);
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> nums{3,10,5,25,2,8};
    cout << test.findMaximumXOR(nums);
    return 0;
}
