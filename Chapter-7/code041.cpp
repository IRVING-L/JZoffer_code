#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MovingAverage
{
public:
    int _size;
    int _total;
    queue<int> Q;
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        _size = size;
        _total = 0;
    }

    double next(int val)
    {
        int sz = Q.size();
        if (sz >= _size)
        {
            _total -= Q.front();
            Q.pop();
            --sz;
        }
        Q.push(val);
        ++sz;
        _total += val;
        double result = _total * 1.0 / (sz * 1.0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    MovingAverage test(3);
    cout<<test.next(1)<<endl;
    cout<<test.next(10)<<endl;
    cout<<test.next(3)<<endl;
    cout<<test.next(5)<<endl;
    return 0;
}
