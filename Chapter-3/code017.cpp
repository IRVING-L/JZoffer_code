#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> hs(256), ht(256);
    string ans("");
    for (auto &c : t)
        ht[c]++;
    int l = 0, r = 0, cnt = 0; //l为窗口的左边界，r为窗口的右边界
    for (; r < s.size(); r++)
    {
        //右边界右移
        hs[s[r]]++;
        if (hs[s[r]] <= ht[s[r]])
            cnt++; //在找到第一个符合条件的窗口后，这个语句不会再运行了。
                   //ps.该语句的作用是统计窗口内的有效字符
        //左边界右移
        while (hs[s[l]] > ht[s[l]])
        {               //这个语句会右移左边界，比如这个边界字符不在t里，
            hs[s[l]]--; //或者符合条件的边界值在后面又增加了一个且和左边界值相同，那么就可以右移左边界
            l++;
        }
        if (cnt == t.size())
        { //有效字符等于字符串t的长度，我们可以放入答案；或者对比前窗口的大小和当前的大小，然后决定是否更新ans。
            if (ans.empty() || r - l + 1 < ans.size())
                ans = s.substr(l, r - l + 1);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str1 = "a", str2 = "b";
    cout << (int)str2[1] << endl;
    cout << minWindow(str1, str2);

    return 0;
}
