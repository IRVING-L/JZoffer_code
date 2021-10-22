#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int len_s = s.length();
    int len_p = p.length();
    if(len_p > len_s)
        return {};
    vector<int> hash_s(26), hash_p(26);

    for(int i=0;i<len_s;++i)
    {
        ++hash_s[s[i] - 'a'];
        ++hash_p[p[i] - 'a'];
    }

    set<string> check;
    vector<int> ans;
    if(hash_s == hash_p)
    {
        check.insert(string(s,0));
        ans.push_back(0);
    }

    for(int i=len_s;i<len_p;++i)
    {
        ++hash_s[s[i] - 'a'];
        --hash_s[s[i-len_p] - 'a'];
        if(hash_s == hash_p)
        {
            string str(s,i-len_p+1,i);
            if(check.find(str)==check.end())
            {
                check.insert(str);
                ans.push_back(i-len_p+1);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = "123456789";
    string str1(str, 1,5);
    cout<<str1<<endl;
    return 0;
}
