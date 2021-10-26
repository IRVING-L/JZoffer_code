#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    unordered_map<char, int> mp;
    int len_s = order.length();
    for (int i = 0; i < len_s; ++i)
    {
        mp[order[i]] = i;
    }
    int sz = words.size();
    for (int i = 0; i < sz - 1; ++i)
    {
        string first = words[i];
        string second = words[i + 1];
        int pos = 0;
        while (first[pos] != '\0' && second[pos] != '\0')
        {
            if (mp[first[pos]] < mp[second[pos]])
                break;
            else if (mp[first[pos]] > mp[second[pos]])
                return false;
            else
                ++pos;
        }
        if (first[pos] == '\0' || mp[first[pos]] < mp[second[pos]])
            continue;
        else
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<string> words{"ubg", "kwh"};

    string order = "qcipyamwvdjtesbghlorufnkzx";
    cout << isAlienSorted(words, order);
    return 0;
}
