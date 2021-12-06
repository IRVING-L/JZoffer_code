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
几天不写力扣，脑子就跟不上了啊
*/
/*
重建序列，这个题，似乎在动规那边，也有相类似的描述

用二维数组seq构建有向图

图的形式为邻接表
另外再保存一个入度数组

*/
class Solution
{
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
    {
        // 建图
        unordered_map<int, unordered_set<int>> graph;
        vector<int> inDegree(org.size() + 1, -1);
        for (auto &seq : seqs)
        {
            for (int &n : seq)
            {
                // 节点需要合法
                if (n < 1 || n > org.size())
                {
                    return false;
                }
                if (!graph.count(n))
                {
                    graph[n] = {};
                }
                if (inDegree[n] == -1)
                {
                    inDegree[n] = 0;
                }
            }
            for (int i = 0; i < seq.size() - 1; ++i)
            {
                int num1 = seq[i];
                int num2 = seq[i + 1];
                if (!graph[num1].count(num2))
                {
                    graph[num1].insert(num2);
                    inDegree[num2]++;
                }
            }
        }

        // 初始化队列
        queue<int> que;
        int index = 0;
        for (int i = 1; i < inDegree.size(); ++i)
        {
            if (inDegree[i] == 0)
            {
                // 存在唯一入度为 0 的节点，且与 org[0] 相等
                if (que.size() == 0 && org[index++] == i)
                {
                    que.push(i);
                }
                else
                {
                    return false;
                }
            }
        }

        // BFS
        while (!que.empty())
        {
            int node = que.front();
            que.pop();
            for (auto &n : graph[node])
            {
                inDegree[n]--;
                if (inDegree[n] == 0)
                {
                    // 每次只存在唯一入度为 0 的节点，且与 org[index] 相等
                    if (que.size() == 0 && org[index++] == n)
                    {
                        que.push(n);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //这句代码很重要，如果seqs生成的序列个数小于org，没这句过不了
        return index == org.size();
    }
};
