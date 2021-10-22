#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    if (len_s1 > len_s2)
        return false;
    // 0-len_s1 check
    vector<int> hash_s1(26), hash_s2(26);
    for (int i = 0; i < len_s1; ++i)
    {
        ++hash_s1[s1[i] - 'a'];
        ++hash_s2[s2[i] - 'a'];
    }
    //check
    if (hash_s1 == hash_s2)
        return true;

    // keep moving
    for (int i = len_s1; i < len_s2; ++i)
    {
        ++hash_s2[s2[i] - 'a'];
        --hash_s2[s2[i - len_s1] - 'a'];
        if (hash_s1 == hash_s2)
            return true;
    }

    return false;
}
int main(int argc, char const *argv[])
{

    return 0;
}
