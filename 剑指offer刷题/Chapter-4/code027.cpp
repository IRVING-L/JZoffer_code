#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *rev = nullptr;
    ListNode *tmp = nullptr;
    while (cur)
    {
        tmp = cur;
        cur = cur->next;
        tmp->next = rev;
        rev = tmp;
    }
    return rev;
}

bool isPalindrome(ListNode *head)
{
    if (head->next == nullptr)
        return true;
    ListNode *fast, *slow;
    fast = slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *front = head;
    ListNode *back = slow->next;
    slow->next = nullptr;

    back = reverseList(back);

    while (front && back)
    {
        if (front->val != back->val)
            return false;
        front = front->next;
        back = back->next;
    }
    return true;
}