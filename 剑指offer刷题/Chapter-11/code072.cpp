#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <random>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 1; 
        int high = x;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mid*mid < x)
            {
                low = mid +1;
            }
            else if(mid*mid > x)
            {
                if((mid-1)*(mid-1) <=x )
                {
                    return mid-1;
                }
                high = mid -1;
            }
            else
            {
                return mid;
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
