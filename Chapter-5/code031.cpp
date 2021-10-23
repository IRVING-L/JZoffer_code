#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache
{
private:
    struct ListNode
    {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y, ListNode *_next, ListNode *_prev) : key(x), val(y), next(_next), prev(_prev) {}
    };
public:
    int _cap = 0;
    int _size = 0;
    ListNode *preHead = nullptr;
    ListNode *tail = nullptr;
    unordered_map<int, ListNode *> mp;
    //移动链表中元素
    void listInsertTail(ListNode *node)
    {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }
    void moveToTail(ListNode *node)
    {
        if(node->next == tail)
            return;
        node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        listInsertTail(node);
    }

public:
    LRUCache(int capacity)
    {
        _cap = capacity;
        preHead = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        preHead->next = tail;
        tail->prev = preHead;
    }

    int get(int key)
    {
        if (!mp.count(key))
            return -1;
        moveToTail(mp[key]);
        return mp[key]->val;
    }

    void put(int key, int value)
    {
        if (!mp.count(key))
        {
            //没有该元素，创建

            if (_size >= _cap)
            {
                ListNode *del = preHead->next;
                preHead->next = del->next;
                del->next->prev = preHead;
                mp.erase(del->key);
                delete del;
                _size--;
            }

            ListNode *tmp = new ListNode(key, value);
            mp[key] = tmp;
            listInsertTail(tmp);
            _size++;
        }
        else
        {
            mp[key]->val = value;
            moveToTail(mp[key]);
        }
    }
};

int main(int argc, char const *argv[])
{
    LRUCache *test = new LRUCache(1);
    test->put(2,1);
    cout<<test->get(2)<<endl;
    test->put(3,2);
    cout<<test->get(2)<<endl
        <<test->get(3)<<endl;
    return 0;
}
