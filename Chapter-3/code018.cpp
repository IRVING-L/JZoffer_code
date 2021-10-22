#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPalindrome(string s)
{
    string str;
    int len = s.length();
    //处理字符串，只保留字母
    for(auto& c:s)
    {
        if(c>='A' && c<='Z')
            str += c;
        else if(c>='a' && c<='z')
            str += (c-32);
        else if(c>='0' && c<='57')
            str += c;
    }
    int n = str.length();
    for(int pos = 0;pos<n/2;++pos)
    {
        if(str[pos] != str[n-pos-1])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string sss = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(sss);
    return 0;
}
