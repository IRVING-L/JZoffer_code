
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

class CBTInserter
{
public:
    queue<TreeNode *> que;
    vector<TreeNode *> Arr;
    TreeNode *_root = nullptr;
    CBTInserter(TreeNode *root)
    {
        Arr.push_back(root);
        _root = root;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *_front = que.front();
            que.pop();
            Arr.push_back(_front);
            if (_front->left != nullptr)
                que.push(_front->left);
            if (_front->right != nullptr)
                que.push(_front->right);
        }
    }

    int insert(int v)
    {
        TreeNode *child = new TreeNode(v);
        int sz = Arr.size();
        TreeNode *father = Arr[(sz / 2)];
        if (father->left == nullptr)
            father->left = child;
        else
            father->right = child;
        Arr.push_back(child);
        return father->val;
    }

    TreeNode *get_root()
    {
        return _root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *left = new TreeNode(2);
    TreeNode *root = new TreeNode(1,left,nullptr);
    CBTInserter test(root);
    cout<<test.insert(3);
    cout<<test.insert(4);
    cout<<3/2<<endl;
    return 0;
}
