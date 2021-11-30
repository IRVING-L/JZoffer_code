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
#include <list>
using namespace std;

/*
其实也就是，无向图的创建和遍历
遍历要使用bfs，因为同一层的顶点，是不冲突的，可以随便加入
*/
/*
有几种特殊情况要注意
图的总顶点数是numCourses
这个图，可以是连通图，也可以是非连通图
连通与否，由先修顺序数组决定
*/
class Solution
{
private:
    vector<vector<int>> Map;
    vector<int> findStart;
    vector<int> vis;
    vector<int> results;
    //有向图的创建
    void biuldMap(vector<vector<int>> &prerequisites)
    {
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            //标记在second中出现的顶点
            findStart[second] = 0;
            Map[first].emplace_back(second);
        }
    }
    void bfs(int start)
    {
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int curr = q.front();
                q.pop();
                if (!findStart[curr])
                {
                    results.emplace_back(curr);
                    vis[curr] = 1;
                    for (int j = 0; j < Map[curr].size(); ++j)
                    {
                        q.push(Map[curr][j]);
                    }
                }
            }
        }
    }
    void helper(int numCourses)
    {
        
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        Map.resize(numCourses, vector<int>());
        findStart.resize(numCourses, 1);
        vis.resize(numCourses);
        biuldMap(prerequisites);
        helper(numCourses);
        return results;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> pres{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution test;
    test.findOrder(4, pres);
    return 0;
}
