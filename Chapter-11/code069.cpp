#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                //递增部分
                low = mid + 1;
            }
            else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
            {
                //递减部分
                high = mid - 1;
            }
            else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
