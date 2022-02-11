#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class RecentCounter
{
public:
    queue<int> que;
    int _size;
    RecentCounter()
    {
        _size = 0;
    }

    int ping(int t)
    {
        que.push(t);
        ++_size;
        while(que.front()+3000<t)
        {
            que.pop();
            --_size;
        }
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
