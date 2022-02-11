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
    int path = 0;
    void RDL(TreeNode *node)
    {
        if(node)
        {
            RDL(node->right);
            int tmp = node->val;
            node->val += path;
            path += tmp;
            RDL(node->left);
        }
    }
    TreeNode *convertBST(TreeNode *root)
    {
        RDL(root);
        return root;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
