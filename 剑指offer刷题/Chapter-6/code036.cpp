#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int str2num(string str)
{
    int num = 0;
    int len = str.length();
    for(int i=len-1;i>=0;--i)
    {
        if(str[i] == '-')
            num=-num;
        else
            num+=(str[i]-'0')*pow(10,(len-1-i));
    }
    return num;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> nums;
    for(auto &str : tokens)
    {
        if(str != "+" && str != "-" && str != "*" && str != "/")
        {
            int number = str2num(str);
            nums.push(number);
        }
        else
        {
            int first, second;
            first = nums.top();
            nums.pop();
            second = nums.top();
            nums.pop();
            switch (str[0]-'\0')
            {
            case 42:
                // *
                nums.push(second * first);
                break;
            case 43:
                // +
                nums.push(second + first);
                break;
            case 45:
                // -
                nums.push(second - first);
                break;
            case 47:
                // /
                nums.push(second / first);
                break;
            
            default:
                break;
            }
        }
    }
    int ans = nums.top();
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> tokens{"2","1","+","3","*"};
    //cout<<evalRPN(tokens)<<endl;
    cout<<str2num("-4")<<endl;
    return 0;
}
