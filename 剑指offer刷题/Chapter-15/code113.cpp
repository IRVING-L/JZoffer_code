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
*/class Solution
{
private:
    //有向图
    vector<vector<int>> Map;
    //入度。
    vector<int> inDeg;
    //答案
    vector<int> results;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        //第0步，初始化数组大小
        Map.resize(numCourses, vector<int>());
        inDeg.resize(numCourses);
        //第一步：创建有向图，初始化入度数组
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            //有向图
            Map[first].push_back(second);
            //入度
            ++inDeg[second];
        }
        //第二步，将所有的入度为0的，放入队列中
        queue<int> q;
        for (int i = 0; i < inDeg.size(); ++i)
        {
            if (inDeg[i] == 0)
                q.push(i);
        }
        //第三步，使用bfs依次遍历入度为0的顶点
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            //把这个入度为0的顶点加入results中
            results.push_back(v);
            //删除顶点v的出度
            for (int i = 0; i < Map[v].size(); ++i)
            {
                int next = Map[v][i];
                --inDeg[next];
                if (inDeg[next] == 0)
                    q.push(next);
            }
        }
        //处理结果
        if(results.size() != numCourses)
            return {};
        return results;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<vector<int>> p{{0,1},{0,2},{1,2}};
    test.findOrder(3,p);
    return 0;
}

