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

class BSTIterator
{
private:
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int idx;

public:
    BSTIterator(TreeNode *root) : idx(0), arr(inorderTraversal(root)) {}

    int next()
    {
        return arr[idx++];
    }

    bool hasNext()
    {
        return (idx < arr.size());
    }
};