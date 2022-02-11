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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
private:
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
    {
        //创建一个新的链表节点
        ListNode *newList = new ListNode(0);
        //创建一个指针记录头
        ListNode *retList = newList;
        //新建两个指针，分别指向两个链表
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        //遍历这两个链表
        while (curr1 && curr2)
        {
            if (curr1->val < curr2->val)
            {
                newList->next = curr1;
                //向前移动指针
                curr1 = curr1->next;
                newList = newList->next;
            }
            else
            {
                newList->next = curr2;
                curr2 = curr2->next;
                newList = newList->next;
            }
        }
        if (curr1)
        {
            newList->next = curr1;
        }
        if (curr2)
        {
            newList->next = curr2;
        }
        return retList->next;
    }
    ListNode *mergeSortLists(vector<ListNode *> &lists, int left, int right)
    {
        //首先，需要明确的是，这个函数是一个递归
        //我们把可以把容器分为两个区间
        //首先，我们先判断一下这个区间的大小，是否足以支撑我们完成后面的操作
        if (left == right)
        {
            //区间长度等于1
            return lists[left];
        }
        //如果left大于right了，怎么处理
        if(left > right)
        {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        ListNode *sortedList1 = mergeSortLists(lists, left, mid);
        ListNode *sortedList2 = mergeSortLists(lists, mid + 1, right);//mid+1有可能会造成越界
        ListNode *mergedAndSortedList = mergeTwoList(sortedList1, sortedList2);
        return mergedAndSortedList;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeSortLists(lists, 0, lists.size()-1);
    }
};