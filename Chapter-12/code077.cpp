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
    ListNode *mergeTwoList(ListNode *l1,ListNode *l2)
    {
        //创建一个新的链表节点
        ListNode *newList = new ListNode(0);
        //创建一个指针记录头
        ListNode *retList = newList;
        //新建两个指针，分别指向两个链表
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        //遍历这两个链表
        while(curr1 && curr2)
        {
            if(curr1->val < curr2->val)
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
        if(curr1)
        {
            newList->next = curr1;
        }
        if(curr2)
        {
            newList->next = curr2;
        }
        return retList->next;
    }
    ListNode *mergeSort(ListNode *head)
    {
        //自顶向下的归并排序
        if(head == nullptr || head->next == nullptr)
            return head;
        //第一步：我们要将以head为头的链表，分成两半
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *first = head;
        ListNode *second = slow->next;
        slow->next = nullptr;
        //得到两条有序链表，合并两条有序链表
        return mergeTwoList(mergeSort(first),mergeSort(second));
    }
public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};