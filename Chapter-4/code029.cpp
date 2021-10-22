#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

Node *insert(Node *head, int insertVal)
{
    Node *data = new Node(insertVal);

    if (head == nullptr)
    {
        return data;
    }
    Node *cur = head;
    do
    {
        //two case
        if (cur->val <= insertVal && cur->next->val >= insertVal)
        {
            data->next = cur->next;
            cur->next = data;
            return head;
        }
        
        cur = cur->next;
    } while (cur != head);
    
    do
    {
        if (cur->val <= insertVal && cur->next->val <= insertVal && cur->val >= cur->next->val)
        {
            data->next = cur->next;
            cur->next = data;
            break;
        }
        if(cur->val >= insertVal && cur->next->val >= insertVal && cur->val >= cur->next->val)
        {
            data->next = cur->next;
            cur->next = data;
            break;
        }
    } while (cur!=head);
    
    return head;
}
