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
using namespace std;

// class Solution
// {
// private:
//     //这个题设外星人的字母一个道理
//     unordered_map<int, int> myHash;
//     auto cmp = [myHash](const int &a, const int &b){
//             return myHash[a] < myHash[b];
//         };
// public:
//     vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
//     {
//         //第一步：把arr2中的数字，按照排列顺序，放在哈希表中
//         for (int i = 0; i < arr2.size(); ++i)
//         {
//             //i值代表了它的排列顺序大小
//             myHash[arr2[i]] = i;
//         }
//         //第二步：把arr1中的元素，按照属于arr2和不属于分开
//         vector<int> part1, part2;
//         for (int i = 0; i < arr1.size(); ++i)
//         {
//             if (myHash.count(arr1[i]))
//             {
//                 part1.emplace_back(arr1[i]);
//             }
//             else
//             {
//                 part2.emplace_back(arr1[i]);
//             }
//         }
//         //对两个容器进行排序
//         sort(part1.begin(),part1.end(),cmp);
//         sort(part2.begin(),part2.end());
//         part1.insert(part1.end(),part2.begin(),part2.end());
//         return part1;
//     }
// };

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        //使用计数排序解决问题
        //第一步：统计arr1每一个数字出现的次数
        int numMax = INT32_MIN;
        int numMin = INT32_MAX;
        for(int &n:arr1)
        {
            numMin = min(n,numMin);
            numMax = max(n,numMax);
        }
        int length = numMax-numMin + 1;
        //第二步：创建一个长度为length的数组
        vector<int> arr(length,0);
        //第三步，统计每一个数字出现的次数
        for(int &n:arr1)
        {
            arr[n-numMin]++;
        }
        //第四步，创建一个排序数组,将和arr2相同的元素加入
        vector<int>  ret;
        for(int &n:arr2)
        {
            while( arr[n-numMin])
            {
                ret.emplace_back(n);
                arr[n-numMin]--;
            }
        }
        //第五步：处理不在arr2中的元素
        for(int i=0;i<arr.size();++i)
        {
            while(arr[i])
            {
                ret.emplace_back(i+numMin);
                arr[i]--;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution test;
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2{2,1,4,3,9,6};
    test.relativeSortArray(arr1,arr2);
    return 0;
}
