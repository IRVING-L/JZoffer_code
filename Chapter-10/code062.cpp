#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

class Trie
{
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        int val;
        vector<TrieNode *> Pointer;
        TrieNode(){}
    };
    TrieNode *head;
    Trie()
    {
        head = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        for(int i=0;i<word.length();++i)
        {
            char ch = word[i];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
    }
};
