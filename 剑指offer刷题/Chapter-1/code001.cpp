#include <iostream>
using namespace std;

int divideCore(int a, int b)
{
    int result = 0;
    int i, count;
    while (a <= b)
    {
        i = b;
        count = 1;
        while (i >= 0xc0000000 && a <= (i + i))
        {
            i += i;
            count += count;
        }
        result += count;
        a -= i;
    }
    return result;
}

int divide(int a, int b)
{
    //0x80000000为最小得int型整数，-2^31
    if (a == 0x80000000 && b == -1)
    {
        return INT32_MAX;
    }
    if(a == 0x80000000 && b == 1)
    {
        return a;
    }
    int flag = 2;
    if (a > 0)
    {
        flag--;
        a = -a;
    }
    if (b > 0)
    {
        flag--;
        b = -b;
    }

    int result = divideCore(a, b);
    return flag == 1 ? -result : result;
}

int main()
{
    cout << divide(0x80000000, 1) << endl;
    return 0;
}