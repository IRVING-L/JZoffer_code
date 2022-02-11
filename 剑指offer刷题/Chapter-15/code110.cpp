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
给定一个有 n 个节点的有向无环图，
用二维数组 graph 表示，请找到所有从 0 到 n-1 的路径并输出（不要求按顺序）。
*/

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> vis;
    void dfs(vector<vector<int>> &graph, int v)
    {
        path.emplace_back(v);
        if (v == graph.size() - 1)
        {
            result.emplace_back(path);
        }
        for (int w = 0; w < graph[v].size(); ++w)
        {
            int next = graph[v][w];
            if (!vis[next])
            {
                dfs(graph, next);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vis.resize(graph.size());
        dfs(graph, 0);
        return result;
    }
};