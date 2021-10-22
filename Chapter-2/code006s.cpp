#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> twoSumHarder(vector<int> &numbers, int target)
{
    //假设数组中存在也许不止一对符合条件的数字
    //同时一个数字不能使用两次。
    vector<vector<int>> ans;
    int sz = numbers.size();
    int low = 0, high = sz -1;
    while(low < high)
    {
        if(numbers[low] + numbers[high] == target)
        {
            ans.push_back({numbers[low],numbers[high]});
            int tmp = numbers[low];
            while(low < high && numbers[low] == tmp)
                ++low;
        }
        else
        {
            if(numbers[low] + numbers[high] < target)
                ++low;
            else
                --high;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6, 10};
    twoSumHarder(v, 8);
    return 0;
}
