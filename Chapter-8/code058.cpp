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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
使用C++中的map容器，它是基于红黑树改造的有序容器
每次要插入一个时间【start，end），
最后一个小于start的、先去找到第一个大于start和
*/

class MyCalendar
{
public:
    map<int, int> st;
    MyCalendar()
    {
    }
    bool book(int start, int end)
    {
        auto it = st.lower_bound(start); // 检查能否查到 it 的左边
        if (it != st.end() && it->first < end)
            return false;
        if (it != st.begin() && (--it)->second > start)
            return false;
        st[start] = end;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    MyCalendar test;
    cout << test.book(48, 50);
    cout << test.book(0, 6);
    cout << test.book(6, 13);
    cout << test.book(8, 13);
    return 0;
}
