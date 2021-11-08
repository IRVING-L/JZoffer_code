#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

class MagicDictionary
{
private:
    struct TrieNode
    {
        char val;
        bool end;
        TrieNode *next[26];
        //构造函数
        TrieNode() {}
        TrieNode(char x)
        {
            val = x;
            end = false;
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };
    TrieNode *head;

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        head = new TrieNode('#');
    }

    void buildDict(vector<string> dictionary)
    {
        for (int i = 0; i < dictionary.size(); ++i)
        {
            TrieNode *curr = head;
            for (int j = 0; j < dictionary[i].length(); ++j)
            {
                char ch = dictionary[i][j];
                if (curr->next[ch - 'a'] == nullptr)
                {
                    TrieNode *data = new TrieNode(ch);
                    curr->next[ch - 'a'] = data;
                }
                curr = curr->next[ch - 'a'];
                if (j == dictionary[i].length() - 1)
                    curr->end = true;
            }
        }
    }
    //要用DFS
    bool dfs(TrieNode *node, string &str, int pos, int edit)
    {
        //返回
        if (node == nullptr)
            return false;
        if (node->end && pos == str.length() && edit == 1)
            return true;
        if (pos < str.length() && edit <= 1)
        {
            bool found = false;
            for (int i = 0; i < 26; ++i)
            {
                //把整个字典树都访问一遍
                int next = (i == (str[pos] - 'a') ? edit : edit + 1);
                found = dfs(node->next[i],str,pos+1,next);
            }
            return found;
        }
        return false;
    }
    bool search(string searchWord)
    {
        return dfs(head, searchWord, 0, 0);
    }
};

int main(int argc, char const *argv[])
{
    MagicDictionary test;
    vector<string> v{"hello", "leetcode"};
    test.buildDict(v);
    cout << test.search("hell");
    cout << test.search("hlllo");

    cout << test.search("helloo");
    cout << test.search("hhlloo");
    return 0;
}
