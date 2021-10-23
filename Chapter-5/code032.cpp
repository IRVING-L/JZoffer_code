#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
    vector<int> s_mp(26),t_mp(26);
    int len_s = s.length();
    int len_t= t.length();
    if(len_s !=len_t)
        return false;
    for(int i=0;i<len_s;++i)
    {
        s_mp[s[i]-'a']++;
        t_mp[t[i]-'a']++;
    }
    if(s_mp != t_mp)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    return 0;
}
