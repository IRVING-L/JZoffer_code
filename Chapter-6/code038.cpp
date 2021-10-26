#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    // int sz = temperatures.size();
    // vector<int> ans;
    // ans.push_back(0);
    // for (int i = sz - 2; i >= 0; --i)
    // {
    //     int j = i + 1;
    //     for (; j < sz; ++j)
    //     {
    //         if (temperatures[j] > temperatures[i])
    //         {
    //             ans.push_back(j - i);
    //             break;
    //         }
    //     }
    //     if (j == sz)
    //         ans.push_back(0);
    // }
    // reverse(ans.begin(), ans.end());
    // return ans;
    //一个单调栈
    stack<int> single_stack;
    single_stack.push(0);
    int sz = temperatures.size();

    vector<int> ans(sz);
    for (int pos = 1; pos < sz; ++pos)
    {
        while (!single_stack.empty() &&  temperatures[pos] > temperatures[single_stack.top()])
        {
            ans[single_stack.top()] = pos - single_stack.top();
            single_stack.pop();
        }
        single_stack.push(pos);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    dailyTemperatures(temp);
    return 0;
}
