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
    // vector<int> arr;

    // void dfs(TreeNode *node)
    // {
    //     if (node != nullptr)
    //     {
    //         dfs(node->left);
    //         arr.push_back(node->val);
    //         dfs(node->right);
    //     }
    // }
    // TreeNode *increasingBST(TreeNode *root)
    // {
    //     dfs(root);
    //     TreeNode *head = new TreeNode(arr.front());
    //     TreeNode *ret = head;
    //     auto it = arr.begin();
    //     for (it++; it != arr.end(); ++it)
    //     {
    //         TreeNode *data = new TreeNode(*it);
    //         head->right = data;
    //         head = head->right;
    //     }
    //     return ret;
    // }
    TreeNode *resNode;
    void inorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);

        // 在中序遍历的过程中修改节点指向
        resNode->right = node;
        node->left = nullptr;
        resNode = node;

        inorder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorder(root);
        return dummyNode->right;
    }
};