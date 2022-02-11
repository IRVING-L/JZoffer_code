#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head)
{
    //快慢指针法
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *ptr1 = head;
    ListNode *ptr2 = fast;
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

int main(int argc, char const *argv[])
{

    return 0;
}
