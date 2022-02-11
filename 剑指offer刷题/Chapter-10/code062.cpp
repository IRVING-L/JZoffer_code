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
    //自定义一个数据结构
    struct TrieNode
    {
        char val;
        bool end;
        //指针数组，强调数组概念，是一个数组变量，数组大小为26，数组内每个元素都是指向TrieNode类型的指针变量。
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
        TrieNode(char x, TrieNode *node)
        {
            val = x;
            end = false;
            int pos = node->val - 'a';
            next[pos] = node;
        }
        //设一个成员函数，修改end的值
        void setEndvalue()
        {
            end = true;
        }
    };
    TrieNode *head;
    Trie()
    {
        head = new TrieNode('#');
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *curr = head;
        for (int i = 0; i < word.length(); ++i)
        {
            char ch = word[i];
            if (curr->next[ch - 'a'] == nullptr)
            {
                TrieNode *data = new TrieNode(ch);
                curr->next[ch - 'a'] = data;
            }
            curr = curr->next[ch - 'a'];
            if(i == word.length() - 1)
                curr->end = true;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *curr = head;
        for (int i = 0; i < word.length(); ++i)
        {
            char ch = word[i];
            if (curr->next[ch - 'a'] == nullptr)
                return false;
            curr = curr->next[ch - 'a'];
        }
        if(curr->end == false)
            return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *curr = head;
        for (int i = 0; i < prefix.length(); ++i)
        {
            char ch = prefix[i];
            if (curr->next[ch - 'a'] == nullptr)
                return false;
            curr = curr->next[ch - 'a'];
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Trie test;
    test.insert("word");
    test.insert("wore");
    test.insert("worf");
    test.insert("worg");
    cout << test.search("wor") << endl;
    cout << test.startsWith("wor") << endl;
    return 0;
}
