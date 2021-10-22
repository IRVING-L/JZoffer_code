#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    int left, right, repeat;
    left = right = 0;
    repeat = 0;
    int ans = 0;
    vector<int> hash_s(256);
    for (; right < len; ++right)
    {
        if (hash_s[(int)s[right]] >= 1)
        {
            ++repeat;
        }
        //repeat变量的存在，负责控制left指针的移动
        while (repeat)
        {
            //如果此时left指针移动到right所指的重复元素，
            if (s[left] == s[right])
                --repeat;
            --hash_s[(int)s[left++]];
        }
        ++hash_s[(int)s[right]];
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = " ";
    cout << str[0] - '0' << (int)str[0] << endl;
    lengthOfLongestSubstring(str);
    return 0;
}
