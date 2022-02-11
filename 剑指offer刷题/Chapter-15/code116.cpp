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

class Solution
{
    //用并查集
    //用一个一维数组表示连通关系
    vector<int> fathers;
    //qiuck-union算法优化的地方在于树的合并，一定是小树合并到大树上最好
    vector<int> sz;
    //查找根节点
    int findFather(int i)
    {
        int fnode = i;
        while(fathers[fnode] != fnode)
        {
            fnode = fathers[fnode];
        }
        return fnode;
    }
    //判断两个顶点的连通性
    bool mkUnion(int i, int j)
    {
        int fatherI = findFather(i);
        int fatherJ = findFather(j);
        if(fatherI == fatherJ)
        {
            //两者连通
            return true;
        }
        else
        {
            //两者不连通,合并
            //判断两个树的高度
            if(sz[i]<sz[j])
            {
                fathers[fatherI] = fatherJ;
                sz[j]+=sz[i];
            }
            else
            {
                fathers[fatherJ] = fatherI;
                sz[i]+=sz[j];
            }
            
            return false;
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        fathers.resize(isConnected.size());
        sz.resize(isConnected.size(),1);
        for(int i=0;i<fathers.size();++i)
        {
            fathers[i] = i;
        }
        //对图的连通性，进行检查和合并
        //定义一个变量count用于统计连通分量的数量
        int count = isConnected.size();
        for(int i=0;i<isConnected.size();++i)
        {
            for(int j=0;j<isConnected[0].size();++j)
            {
                if(isConnected[i][j])
                {
                    //i,j是连通的
                    //每调用mkunion函数合并一次，都需要对计数-1；
                    count = (mkUnion(i,j)?count:count-1);
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
