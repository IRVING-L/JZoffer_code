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
给定一个变量对数组 equations 和一个实数值数组 values 作为已知条件，

其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。

每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，

请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。

如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。


*/
class Solution
{
private:
    struct Vertex
    {
        string v;
        double edge;
        Vertex(){};
        Vertex(string str, double x) : v(str), edge(x) {}
    };
    map<string, vector<Vertex>> Map;
    //用于dfs函数避免重复访问的辅助数组
    unordered_map<string, int> vis;
    //返回的答案数组
    vector<double> results;
    //创建，有向带权图
    void biuldMap(vector<vector<string>> &equations,
                  vector<double> &values)
    {
        for (int i = 0; i < equations.size(); ++i)
        {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            double result = values[i];
            Map[v1].push_back(Vertex(v2, result));
            Map[v2].push_back(Vertex(v1, 1 / result));
            //VIS哈希表的创建
            vis[v1] = 0;
            vis[v2] = 0;
        }
    }
    //dfs search
    inline bool dfs(string &start, const string &end, double path)
    {
        if (start != end)
        {
            bool state = false;
            vis[start] = 1;
            //遍历到最后一个顶点了，还是没有找到，这种情况要单独处理
            for (int i = 0; i < Map[start].size(); ++i)
            {
                string nextVertex = Map[start][i].v;
                double edgeValue = Map[start][i].edge;
                if (!vis[nextVertex])
                {
                    state = state || dfs(nextVertex, end, path * edgeValue);
                }
            }
            vis[start] = 0;
            return state;
        }
        else
        {
            //找到了
            results.emplace_back(path);
            return true;
        }
    }
    void helper(vector<vector<string>> &queries)
    {
        for (int i = 0; i < queries.size(); ++i)
        {
            //取出那两个单词
            string first = queries[i][0];
            string second = queries[i][1];
            //如果单词不在图中，未知情况，直接置为-1.0
            if (vis.count(first) && vis.count(second))
            {
                bool isWorked = dfs(first, second, 1.0);
                if (!isWorked)
                    results.emplace_back(-1.0);
            }
            else
            {
                results.emplace_back(-1.0);
            }
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        biuldMap(equations, values);
        //创建完图，下一步就是使用dfs搜索图
        helper(queries);
        //处理返回结果
        return results;
    }
};