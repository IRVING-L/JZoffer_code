#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int timeTrans(string str)
{
    int mins = 0;
    int hours = 0;
    hours = (str[0] - '0') * 10 + (str[1] - '0');
    mins = hours * 60 + (str[3] - '0') * 10 + (str[4] - '0');
    return mins;
}

int findMinDifference(vector<string> &timePoints)
{
    vector<int> times;
    bool hs[2160]={};
    for (auto &str : timePoints)
    {
        int time = timeTrans(str);
        hs[time] = true;
        if(time<720)
            hs[time + 1440] = true;
    }
    int ans = INT32_MAX;
    int left=0,right=0;
    while(!hs[right])
        ++right;
    left = right;
    while(right<2160)
    {
        ++right;
        if(hs[right])
        {
            int dis = right-left;
            ans = dis<ans? dis : ans;
            left = right;
        }
    }
    return ans;
    
}
int main(int argc, char const *argv[])
{
    string str = "01:00";
    cout << timeTrans(str) << endl;
    return 0;
}
