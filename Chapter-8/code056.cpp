#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> arr;
    void inOrder(TreeNode *node)
    {
        if (node)
        {
            inOrder(node->left);
            arr.emplace_back(node->val);
            inOrder(node->right);
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        inOrder(root);
        int l=0,r=arr.size()-1;
        while(l < r)
        {
            if(arr[l] + arr[r] < k)
                ++l;
            else if(arr[l] + arr[r] > k)
                --r;
            else
                return true;
        }
        return false;
    }
};