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

void reorderList(ListNode *head)
{
    if (head->next == nullptr)
        return;
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

    ListNode *ptr1, *ptr2;

    while (front && back)
    {
        ptr1 = front;
        front = front->next;
        ptr1->next = back;

        ptr2 = back;
        back = back->next;
        ptr2->next = front;
    }
}

int main(int argc, char const *argv[])
{
    ListNode *ls1 = new ListNode(4);
    ListNode *ls2 = new ListNode(3, ls1);
    ListNode *ls3 = new ListNode(2, ls2);
    ListNode *ls4 = new ListNode(1, ls3);

    reorderList(ls4);

    return 0;
}
