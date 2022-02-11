#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};


Node *dfs(Node *node)
{
    if(node==nullptr)   return node;
    //D
    Node *cur = node;
    //L
    Node *_next = cur->next;
    //R
    Node *childTail = nullptr;
    if(cur->child != nullptr)
    {
        childTail = dfs(cur->child);
    }
    if(childTail)
    {
        childTail->next = cur->next;
        cur->next->prev = childTail;
        cur->next = cur->child;
        cur->child->prev = cur;
    }
    return node;
}

Node *flatten(Node *head)
{
    head = dfs(head);
    return head;
}