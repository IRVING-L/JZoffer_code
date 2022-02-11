#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
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

string strNum;
vector<int> nums;
int ans = 0;

void dfs(TreeNode *node)
{
    if (node != nullptr)
    {
        nums.push_back(node->val);

        dfs(node->left);

        dfs(node->right);

        if (node->left == nullptr && node->right == nullptr)
        {
            int sz = nums.size();
            int num = 0;
            for (int i = sz - 1; i >= 0; --i)
            {
                num += pow(10, sz - 1 - i) * nums[i];
            }
            ans += num;
        }
        nums.pop_back();
    }
}

int sumNumbers(TreeNode *root)
{
    dfs(root);
    return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(9, node1, node2);
    TreeNode *node4 = new TreeNode(0);
    TreeNode *root = new TreeNode(4, node3, node4);
    sumNumbers(root);
    return 0;
}
