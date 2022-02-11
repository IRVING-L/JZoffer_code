#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

TreeNode *dfs(TreeNode *node)
{
    if(node == nullptr)
        return node;
    
    node->left = dfs(node->left);
    node->right = dfs(node->right);

    if(node->left == nullptr && node->right == nullptr && node->val == 0)
    {
        //剪枝
        return nullptr;
    }
    return node;
}

TreeNode *pruneTree(TreeNode *root)
{
    root = dfs(root);
    return root;
}

int main(int argc, char const *argv[])
{
    TreeNode *node1 = new TreeNode(0);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(0,node1,node2);
    TreeNode *node4 = new TreeNode(1,nullptr,node3);
    
    pruneTree(node4);
    return 0;
}
