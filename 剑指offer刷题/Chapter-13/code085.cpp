#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>
using namespace std;

/*
正整数 n 代表生成括号的对数，
请设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/

// class Solution
// {
// private:
//     string comb;
//     vector<string> ret;
//     void swap(string &str, int i, int j)
//     {
//         char tmp = str[i];
//         str[i] = str[j];
//         str[j] = tmp;
//     }
//     //思路：全排列+check
//     //检查check函数
//     bool check()
//     {
//         //预处理：把序号组合拷贝一下
//         string str = comb;
//         //创建 st 栈
//         stack<char> st;
//         if (str[0] != '(')
//             return false;
//         st.push(str[0]);
//         for (int i = 1; i < str.length(); ++i)
//         {
//             if (str[i] == '(')
//             {
//                 st.push(str[i]);
//             }
//             else
//             {
//                 if (!st.empty() || st.top() == ')')
//                 {
//                     //不能组合成一对括号，错误
//                     return false;
//                 }
//                 //能够组成一对括号
//                 st.pop();
//             }
//         }
//         return true;
//     }

//     //全排列函数
//     void permute(int startIndex)
//     {
//         if (startIndex == comb.length())
//         {
//             //check是否为有效的括号组合
//             if (check())
//             {
//                 ret.emplace_back(comb);
//             }
//             return;
//         }
//         vector<int> hs(2); //用数组模拟哈希表，去重
//         for (int i = startIndex; i < comb.length(); ++i)
//         {
//             if (hs[comb[i]-40])
//             {
//                 continue;
//             }
//             else
//             {
//                 hs[comb[i]-40] = 1;
//                 swap(comb, i, startIndex);
//                 permute(startIndex + 1);
//                 swap(comb, i, startIndex);
//             }
//         }
//     }

// public:
//     vector<string> generateParenthesis(int n)
//     {
//         for (int i = 0; i < n; ++i)
//         {
//             comb.push_back('(');
//             comb.push_back(')');
//         }
//         permute(0);
//         return ret;
//     }
// };
class Solution
{
private:
    vector<string> result;
    void backtrack(int left, int right, string path)
    {
        if(left ==0 && right ==0)
        {
            result.push_back(path);
            return;
        }
        if(left > 0)
        {
            //添加左括号
            backtrack(left-1,right,path+'(');
        }
        if(left < right)
        {
            backtrack(left,right-1,path+')');
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        backtrack(n,n,"");
        return result;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
