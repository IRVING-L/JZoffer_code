#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int function(string s, int left, int right)
{
    int count = 0;
    while (left >= 0 && right < s.length())
    {
        if (s[left] == s[right])
        {
            ++count;
            --left;
            ++right;
        }
        else
            break;
    }
    return count;
}

int countSubstrings(string s)
{
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        //奇数
        ans += function(s, i, i);
        //偶数
        ans += function(s, i, i + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
