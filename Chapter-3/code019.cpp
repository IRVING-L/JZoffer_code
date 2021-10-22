#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left, right;
        left = 0;
        right = s.length()-1;
        int flag = 1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                ++left;
                --right;
                continue;
            }
            else
            {
                if(check(s,left+1,right) || check(s,left,right-1))
                {
                    return true;
                }
                else
                    return false;
            }
        }
        return true;
    }
private:
    bool check(string &s, int left, int right)
    {
        while(left<=right)
        {
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    //cout << validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    return 0;
}
