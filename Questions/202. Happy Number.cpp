/*
202. Happy Number
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
1 <= n <= 2^31 - 1
*/

#include<bits/stdc++.h>
using namespace std;

int returnSquare(int num)
{
    int temp=0;
    while(num!=0)
    {
        int x = num%10;
        temp = temp + x*x;
        num = num/10;
    }
    return temp;
}

bool isHappy(int n)
{
    if(n==1 || n==7 || n==10) return true;
    if(n<10) return false;
    return isHappy(returnSquare(n));
}

int main()
{
    int n;
    cout<<"Enter a number to check whether it is a Happy Number or Not : ";
    cin>>n;

    if(isHappy(n)) cout<<"true";
    else cout<<"false";
    return 0;
}
