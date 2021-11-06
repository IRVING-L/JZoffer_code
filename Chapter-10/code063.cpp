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
        TrieNode(char x, TrieNode *node)
        {
            val = x;
            end = false;
            int pos = node->val - 'a';
            next[pos] = node;
        }
    };

    //头结点
    TrieNode *head;
    void creatDicTree(vector<string> &dic)
    {
        for (int i = 0; i < dic.size(); ++i)
        {
            TrieNode *curr = head;
            for (int j = 0; j < dic[i].length(); ++j)
            {
                char ch = dic[i][j];
                if (curr->next[ch - 'a'] == nullptr)
                {
                    TrieNode *data = new TrieNode(ch);
                    curr->next[ch - 'a'] = data;
                }
                curr = curr->next[ch - 'a'];
                if (j == dic[i].length() - 1)
                    curr->end = true;
            }
        }
    }
    void checkWords(vector<string> &words, string &output)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            TrieNode *curr = head;
            //如果第一个字符匹配不上，那就不用继续了
            if (curr->next[words.front().front() - 'a'] == nullptr)
            {
                output += (words.front() + " ");
                continue;
            }
            string str;
            for (int j = 0; j < words[i].length(); ++j)
            {
                char ch = words[i][j];
                if (curr->next[ch - 'a'])
                {
                    str += ch;
                    if (curr->next[ch - 'a']->end)
                    {
                        output += str + " ";
                        break;
                    }
                    curr = curr->next[ch - 'a'];
                }
                else
                    break;
            }
        }
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        //把字典放在前缀树中
        creatDicTree(dictionary);
        //把string的sentence单词分离出来
        vector<string> words;
        string str;
        for (int i = 0; i < sentence.length(); ++i)
        {
            if (isspace(sentence[i]))
            {
                words.emplace_back(str);
                str = "";
                continue;
            }
            str += sentence[i];
        }
        //把每一个单词在字典树中进行比较，没有就返回原单词，有的就返回第一个能比较的
        string ret;
        checkWords(words, ret);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> dic{"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution test;
    test.replaceWords(dic, sentence);
    return 0;
}
