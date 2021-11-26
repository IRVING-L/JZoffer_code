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

/*

二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B 
并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合
就将这个图称为 二分图 。

*/
/*
不要被二分图的定义所迷惑
换个思路思考：如果一个图是二分图，一个子集的顶点标为红色，另一个标为黑色。
相邻的顶点，颜色必须不同，否则不是二分图
这样描述一遍二分图，你还不会做吗？
*/
class Solution
{
private:
    //二分图颜色的标记
    vector<int> rb; // red or black
    
    bool DFS(vector<vector<int>> &graph, int v)
    {
        bool flag = true;
        for (int w = 0; w < graph[v].size(); ++w)
        {
            //首先，判断相邻顶点有没有颜色，有颜色的检查颜色对不对
            int next = graph[v][w];
            if(rb[next] != 0 )
            {
                //有颜色。如果两顶点颜色相同，则返回错误
                if(rb[next] == rb[v])
                    flag = false;
            }
            else
            {
                //没有颜色，也代表这个顶点还没有访问过
                rb[next] = -rb[v]; // 颜色取反
                flag = DFS(graph, next);
            }
        }
        return flag;
    }
    bool bfs(vector<vector<int>> &graph, int v)
    {
        queue<int> q;
        bool flag = true;
        q.push(v);
        rb[v] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int w = 0; w < graph[curr].size(); ++w)
            {
                int next = graph[curr][w];
                if (rb[next] != 0)
                {
                    //有颜色
                    if (rb[next] == rb[curr])
                        flag = false;
                }
                else
                {
                    //没有颜色，也代表这个顶点还没有访问过
                    rb[next] = -rb[curr]; // 颜色取反
                    q.push(next);
                }
            }
        }
        return flag;
    }
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        rb.resize(graph.size());
        //由于题目中的数据，存在非连通图，所以要用一个for循环，才能遍历完所有的图
        for (int i = 0; i < rb.size(); ++i)
        {
            if (rb[i] == 0)
            {
                if(!bfs(graph, i))
                    return false;
            }
        }
        return true;
    }
};