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
/*
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
*/
/*
理一下官方答案
上面的代码，我遍历二维数组中 不为0的数，寻找离该元素最近的0
这样代码可以写出来，但是时间花费很大，通过不了

官方的解答是这样的：
把二维数组中的0看成是一块，放在队列中，使用bfs
bfs每往外搜索一层，也就是找到了距离+1的fei0元素
填满整个二维数组，答案就出来了


*/
class Solution
{

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        //把二维数组中，所有的0元素都放在队列中
        int rows = mat.size();
        int cols = mat[0].size();
        queue<vector<int>> q;
        //返回结果，并将数组的元素全都初始化为最大值
        vector<vector<int>> result(rows, vector<int>(cols, INT32_MAX));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (mat[i][j] == 0)
                {
                    //使用vector保存二维坐标，第一个位置存放x坐标，第二个位置存放y坐标
                    //第三个位置存放距离0的距离
                    q.push({i, j});
                }
            }
        }
        //使用队列，bfs遍历元素
        while (!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            //遍历上下左右四个方向的相邻顶点
            //up
            if (x - 1 >= 0 && result[x - 1][y] == INT32_MAX)
            {
                result[x - 1][y] = result[x][y] + 1;
                q.push({x - 1, y});
            }
            //down
            if (x + 1 < rows && result[x + 1][y] == INT32_MAX)
            {
                result[x + 1][y] = result[x][y] + 1;
                q.push({x + 1, y});
            }
            //left
            if (y - 1 >= 0 && result[x][y - 1] == INT32_MAX)
            {
                result[x][y - 1] = result[x][y] + 1;
                q.push({x, y - 1});
            }
            //up
            if (y + 1 < cols && result[x][y + 1] == INT32_MAX)
            {
                result[x][y + 1] = result[x][y] + 1;
                q.push({x, y + 1});
            }
        }
        return result;
    }
};