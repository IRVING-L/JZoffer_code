#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet
{
public:
    unordered_map<int, int> hash;
    vector<int> arr;
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (hash.count(val))
            return 0;
        hash[val] = arr.size();
        arr.push_back(val);
        return 1;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (!hash.count(val))
            return 0;
        //交换数组中要删除的元素 和 最后一个元素
        hash[arr.back()] = hash[val];
        arr[hash[val]] = arr.back();
        hash.erase(val);
        arr.pop_back();
        
        return 1;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
