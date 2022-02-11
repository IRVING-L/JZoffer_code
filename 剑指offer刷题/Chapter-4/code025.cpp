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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *rev_l1 = reverseList(l1);
    ListNode *rev_l2 = reverseList(l2);

    int carry = 0;
    ListNode *ans = new ListNode();
    while (rev_l1 && rev_l2)
    {
        int tmp = rev_l1->val + rev_l2->val + carry;
        carry = tmp > 9 ? 1 : 0;
        tmp = tmp > 9 ? tmp % 10 : tmp;
        ListNode *data = new ListNode(tmp, ans->next);
        ans->next = data;

        rev_l1 = rev_l1->next;
        rev_l2 = rev_l2->next;
    }
    while (rev_l1)
    {
        int tmp = rev_l1->val + carry;
        carry = tmp > 9 ? 1 : 0;
        tmp = tmp > 9 ? tmp % 10 : tmp;
        ListNode *data = new ListNode(tmp, ans->next);
        ans->next = data;
        rev_l1 = rev_l1->next;
    }
    while (rev_l2)
    {
        int tmp = rev_l2->val + carry;
        carry = tmp > 9 ? 1 : 0;
        tmp = tmp > 9 ? tmp % 10 : tmp;
        ListNode *data = new ListNode(tmp, ans->next);
        ans->next = data;
        rev_l2 = rev_l2->next;
    }
    if (carry)
    {
        ListNode *data = new ListNode(carry, ans->next);
        ans->next = data;
    }
    return ans->next;
}

int main(int argc, char const *argv[])
{
    return 0;
}
