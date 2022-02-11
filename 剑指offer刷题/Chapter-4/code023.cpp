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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    //解法1
    // unordered_map<ListNode*, int> mp;
    // ListNode *ptr_a = headA;
    // ListNode *ptr_b = headB;
    // while (ptr_a)
    // {
    //     mp[ptr_a]++;
    //     ptr_a = ptr_a->next;
    // }
    // while (ptr_b)
    // {
    //     if(mp.find(ptr_b)!=mp.end())
    //         break;
    //     ptr_b = ptr_b->next;
    // }
    // return ptr_b;
    //解法2
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *ptr_a = headA;
    ListNode *ptr_b = headB;
    while (ptr_a != ptr_b)
    {
        ptr_a = ptr_a == NULL ? headB : ptr_a->next;
        ptr_b = ptr_b == NULL ? headA : ptr_b->next;
    }
    return ptr_a;
}
int main(int argc, char const *argv[])
{

    return 0;
}
