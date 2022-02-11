#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    string result;
    int len_a = a.length() - 1;
    int len_b = b.length() - 1;
    int carry = 0;
    while (len_a >= 0 || len_b >= 0)
    {
        int digital_a = (len_a >= 0 ? a[len_a--] - '0' : 0);
        int digital_b = (len_b >= 0 ? b[len_b--] - '0' : 0);
        int sum = digital_a + digital_b + carry;
        carry = (sum >= 2 ? 1 : 0);
        sum = (sum >= 2 ? sum - 2 : sum);
        result.push_back(sum + '0');
    }
    if (carry)
    {
        result.push_back('1');
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    cout << addBinary("1101", "0011") << endl;
    return 0;
}