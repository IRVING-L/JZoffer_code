#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
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
    // int ans = 0;
    // void dfs(TreeNode *node, int path, int targetSum)
    // {
    //     if (node == nullptr)
    //         return;
    //     path += node->val;
    //     if (path == targetSum)
    //         ++ans;
    //     //L
    //     dfs(node->left, path, targetSum);
    //     //R
    //     dfs(node->right, path, targetSum);

    //     path -= node->val;
    // }
    // void func(TreeNode *root, int targetSum)
    // {
    //     if (root == nullptr)
    //         return;
    //     dfs(root, 0, targetSum);
    //     func(root->left, targetSum);
    //     func(root->right, targetSum);
    // }
    // int pathSum(TreeNode *root, int targetSum)
    // {
    //     func(root, targetSum);
    //     return ans;
    // }
    //前缀和
    int ans = 0;
    unordered_map<int, int> hmp;
    void dfs(TreeNode *node, int path, int targetSum)
    {
        if (node == nullptr)
            return;
        path += node->val;
        if (hmp.find(path - targetSum) != hmp.end())
        {
            ans += hmp[path - targetSum];
        }
        hmp[path]++;
        dfs(node->left, path, targetSum);
        dfs(node->right, path, targetSum);
        hmp[path]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        hmp[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *node1 = new TreeNode(-3);
    TreeNode *node2 = new TreeNode(-2, nullptr, node1);
    Solution test;
    cout << test.pathSum(node2, -2);
    return 0;
}
