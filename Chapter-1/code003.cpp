#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void countBits(int n)
{
    vector<int> ans;
    //solution 1
    // for (unsigned int i = 0; i <= n; ++i)
    // {
    //     int j = i;
    //     int cnt = 0;
    //     while (j != 0)
    //     {
    //         cnt++;
    //         j = j & (j - 1);
    //     }
    //     ans.push_back(cnt);
    // }
    //solution 2
    // ans.push_back(0);
    // for (int i = 1; i <= n; ++i)
    // {
    //     int pos = i & (i - 1);
    //     ans.push_back(ans[pos] + 1);
    // }
    //solution 3
    ans.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        i % 2 ? ans.push_back(ans[i / 2] + 1) : ans.push_back(ans[i / 2]);
    }
    
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    countBits(4);
    return 0;
}