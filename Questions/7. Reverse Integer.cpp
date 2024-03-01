/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:

-2^31 <= x <= 2^31 - 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rev(string& x)
    {
        string x1 = x;
        x="";
        for(int i=x1.length()-1;i>=0;i--)
        {
            x += x1[i];
        }
    }
    int reverse(int x)
    {
        string s = to_string(x);
        rev(s);
        long long int a = stoll(s);
        if(a>2147483647 || a<-2147483648)   return 0;
        if(x<0){ a= a*-1;}
        return a;
    }
};

int main()
{
    int x;
    cin>>x;
    Solution s;
    cout<<s.reverse(x);
    return 0;
}
