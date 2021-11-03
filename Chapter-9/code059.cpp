#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

class BigHeap
{
private:
    vector<int> _Array;
    int arr_size = 0;
    void sink(int loc, int length)
    {
        while (2 * loc <= length)
        {
            int lchild = 2 * loc;
            if ((lchild + 1) < length && _Array[lchild] < _Array[lchild + 1])
                ++lchild;
            if (_Array[loc] > _Array[lchild])
                break;
            //swap
            swap(_Array[loc], _Array[lchild]);

            loc = lchild;
        }
    }

public:
    BigHeap() {}
    BigHeap(vector<int> &nums)
    {
        arr_size = nums.size();
        _Array.resize(arr_size + 1);
        //复制元素
        for (int i = 1; i <= arr_size; ++i)
            _Array[i] = nums[i - 1];
        //构造大根堆
        for (int i = arr_size / 2; i > 0; --i)
            sink(i, arr_size);
        //用大根堆进行排序
        for (int i = arr_size; i > 1; --i)
        {
            swap(_Array[1], _Array[i]);
            sink(1, i - 1);
        }
    }
};

class KthLargest
{
private:
    vector<int> _Array;
    int arr_size = 0;
    int _k;
    void sink(int loc, int length)
    {
        while (2 * loc <= length)
        {
            int lchild = 2 * loc;
            if ((lchild + 1) < length && _Array[lchild] < _Array[lchild + 1])
                ++lchild;
            if (_Array[loc] > _Array[lchild])
                break;
            //swap
            swap(_Array[loc], _Array[lchild]);

            loc = lchild;
        }
    }
    void swim(int loc)
    {
        while (loc > 1 && _Array[loc] < _Array[loc / 2])
        {
            //swap
            swap(_Array[loc],_Array[loc/2]);
            loc /= 2;
        }
    }

public:
    KthLargest(int k, vector<int> &nums)
    {
        arr_size = nums.size();
        _k = k;
        _Array.resize(arr_size + 1);
        //复制元素
        for (int i = 1; i <= arr_size; ++i)
            _Array[i] = nums[i - 1];
        //构造大根堆
        for (int i = arr_size / 2; i > 0; --i)
            sink(i, arr_size);
        //用大根堆进行排序
        for (int i = arr_size; i > 1; --i)
        {
            swap(_Array[1], _Array[i]);
            sink(1, i - 1);
        }
    }

    int add(int val)
    {
        _Array.push_back(val);
        arr_size++;
        swap(_Array[1], _Array[arr_size]);
        sink(1, arr_size - 1);
        return _Array[arr_size - _k + 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{4, 5, 8, 2};
    KthLargest test(3, nums);
    cout << test.add(3) << endl;
    return 0;
}
