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

class Solution
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
    TrieNode *head = new TrieNode('^');
    //成员函数
    //创建 ”后缀树“
    void biuldReTrie(vector<string> &words)
    {
        //用words中正序的单词，创建一个后缀树
        for (int i = 0; i < words.size(); ++i)
        {
            TrieNode *curr = head;
            for (int j = words[i].length() - 1; j >= 0; --j)
            {
                char ch = words[i][j];
                if (curr->next[ch - 'a'] == nullptr)
                {
                    TrieNode *data = new TrieNode(ch);
                    curr->next[ch - 'a'] = data;
                }
                curr = curr->next[ch - 'a'];
            }
            curr->end = true;
        }
    }
    //深度遍历，统计每一条路径的长度
    void countLength(TrieNode *node, int length, int &sum)
    {
        bool isLeaf = true; //定义一个判断叶子节点变量
        for (int direc = 0; direc < 26; ++direc)
        {
            if (node->next[direc] != nullptr)
            {
                isLeaf = true;
                countLength(node->next[direc], length+1, sum);
            }
        }
        if(isLeaf)
        {
            //isLeaf没有经过修改，代表这个节点已经是叶子节点了，可以统计长度了
            sum += length;
        }
    }

public:
    int minimumLengthEncoding(vector<string> &words)
    {
        biuldReTrie(words);
        int ans = 0;
        countLength(head,1,ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v{"at", "hat", "cat"};
    Solution test;
    cout << test.minimumLengthEncoding(v);
    return 0;
}
