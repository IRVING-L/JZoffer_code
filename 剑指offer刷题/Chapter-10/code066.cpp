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

class MapSum
{
private:
    struct TrieNode
    {
        int val;
        TrieNode *next[26];
        //构造函数
        TrieNode() {}
        TrieNode(int x)
        {
            val = x;
            for (int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };
    TrieNode *head;
    
    void dfs(TrieNode *node, int &sum)
    {
        sum += node->val;
        for (int i = 0; i < 26; ++i)
        {
            if (node->next[i] != nullptr)
            {
                dfs(node->next[i], sum);
            }
        }
    }

public:
    /** Initialize your data structure here. */
    MapSum()
    {
        head = new TrieNode(0);
    }

    void insert(string key, int val)
    {
        TrieNode *curr = head;
        for (int i = 0; i < key.length(); ++i)
        {
            char ch = key[i];
            if (curr->next[ch - 'a'] == nullptr)
            {
                TrieNode *data = new TrieNode(0);
                curr->next[ch - 'a'] = data;
            }
            curr = curr->next[ch - 'a'];
        }
        curr->val = val;
    }

    int sum(string prefix)
    {
        int ret = 0;
        TrieNode *curr = head;
        for (int i = 0; i < prefix.length(); ++i)
        {
            char ch = prefix[i];
            if (curr->next[ch - 'a'] == nullptr)
                return ret;
            curr = curr->next[ch - 'a'];
        }
        dfs(curr, ret);
        return ret;
    }
};