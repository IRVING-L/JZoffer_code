#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 *解题思路：BFS
 对矩阵中的每一个元素都进行一个BFS
 有两种情况：
    1.该元素值==0，那么最近的0就是它自己，不需要BFS
    2.不等于0，使用BFS，BFS每搜索一层，就是距离+1，
    用一个计数器保存搜索的深度，当搜索到第i层，找到了一个0，那么得到结果为i
*/
class Solution
{
private:
    vector<vector<int>> result;
    
    int bfs(vector<vector<int>> &mat, int i, int j)
    {
        queue<vector<int>> q;
        int count = 0;
        vector<vector<bool>> vis(mat.size(),vector<bool>(mat[0].size()));
        vector<int> tmp{i,j,count};
        vis[i][j] = 1;
        q.push(tmp);  
        while (!q.empty())
        {
            //上下左右四个方向，相邻的元素都是邻顶点
            int originX = q.front()[0];
            int originY = q.front()[1];
            int currLevel = q.front()[2];
            q.pop();
            //up
            if (originX - 1 >= 0 && !vis[originX - 1][originY])
            {
                if (mat[originX - 1][originY] == 0)
                {
                    count = currLevel + 1;
                    break;
                }
                vis[originX - 1][originY] = 1;
                q.push({originX - 1, originY, currLevel + 1});
            }
            //down
            if (originX + 1 < mat.size() && !vis[originX + 1][originY])
            {
                if (mat[originX + 1][originY] == 0)
                {
                    count = currLevel + 1;
                    break;
                }
                vis[originX + 1][originY];
                q.push({originX + 1, originY, currLevel + 1});
            }
            //left
            if (originY - 1 >= 0 && !vis[originX][originY - 1])
            {
                if (mat[originX][originY - 1] == 0)
                {
                    count = currLevel + 1;
                    break;
                }
                vis[originX][originY - 1];
                q.push({originX, originY - 1, currLevel + 1});
            }
            //right
            if (originY + 1 < mat[0].size() && !vis[originX][originY + 1])
            {
                if (mat[originX][originY + 1] == 0)
                {
                    count = currLevel + 1;
                    break;
                }
                vis[originX][originY + 1];
                q.push({originX, originY + 1, currLevel + 1});
            }
        }
        return count;
    }
    void helper(vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                if (mat[i][j] == 0)
                    result[i][j] = 0;
                else
                {
                    
                    result[i][j] = bfs(mat, i, j);
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        result.resize(mat.size(), vector<int>(mat[0].size()));
        
        helper(mat);
        return result;
    }
};