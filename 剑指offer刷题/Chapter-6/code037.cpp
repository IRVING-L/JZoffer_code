#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    vector<int> ans;
    int sz = asteroids.size();
    for (int i = 0; i < sz; ++i)
    {
        int star = asteroids[i];
        if (star > 0)
            st.push(star);
        else
        {
            while (!st.empty() && star)
            {
                if (st.top() > abs(star))
                    break;
                else if (st.top() < abs(star))
                    st.pop();
                else
                {
                    st.pop();
                    star = 0;
                }
            }
            if (st.empty() && star)
                ans.push_back(star);
        }
    }
    stack<int> tmp;
    while (!st.empty())
    {
        tmp.push(st.top());
        st.pop();
    }
    while (!tmp.empty())
    {
        ans.push_back(tmp.top());
        tmp.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2, -1, 1, 2};
    asteroidCollision(nums);
    return 0;
}
