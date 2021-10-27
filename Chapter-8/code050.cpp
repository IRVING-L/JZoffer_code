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
    int dfs(TreeNode *root, int targetSum, unordered_map<int,int> mp, int path)
    {
        if(root = nullptr)
            return 0;
        //D
        path += root->val;
        
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        return dfs(root, targetSum, mp, 0);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
