#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


int m = 4, n =3;
int singleNumber(vector<int> &nums)
{
//解法1：哈希表，时间复杂度O(n)，空间复杂度O(n)
    // unordered_map<int,int> Map;
    // for(auto it = nums.begin();it!=nums.end();++it)
    // {
    //     Map[*it]++;
    // }
    // int rel = -1;
    // for(auto it = Map.begin();it!=Map.end();++it)
    // {
    //     if(it->second == 1)
    //     {
    //         rel = it->first;
    //         return rel;
    //     }
    // }
    // return rel;
//解法2：位运算
    
    int ret = 0;
    for(int i=0;i<32;++i)
    {
        int tmp = 0;
        for(int num : nums)
        {
            tmp += num >> (31-i) & 1;
        }
        ret = (ret << 1) + (tmp % m )/ n;
    }
    return ret;
}

int main()
{
    vector<int> v{2,2,3,2,2,3,3};
    cout<<singleNumber(v);
    return 0;
}