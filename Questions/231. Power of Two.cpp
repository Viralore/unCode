/*
231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false


Constraints:
-2^31 <= n <= 2^31 - 1
*/

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    while(n>1 && n%2==0)
    {
        n/=2;
    }
    return n==1?true:false;
}

int main()
{
    int n;
    cout<<"Enter the number to check for the power of two : ";
    cin>>n;
    if(isPowerOfTwo(n)) cout<<"true";
    else cout<<"false";
    return 0;
}
