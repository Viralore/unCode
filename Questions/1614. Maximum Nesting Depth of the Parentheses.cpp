/*
1614. Maximum Nesting Depth of the Parentheses

A string is a valid parentheses string (denoted VPS) if it meets one of the following:
1. It is an empty string "", or a single character not equal to "(" or ")",
2. It can be written as AB (A concatenated with B), where A and B are VPS's, or
3. It can be written as (A), where A is a VPS.

We can similarly define the nesting depth depth(S) of any VPS S as follows:
i.   depth("") = 0
ii.  depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
iii. depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
iv.  depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3

Constraints:
1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxDepth(string s) 
    {
        int ans = 0;
        int opened = 0;
        for (char c : s)
        if (c == '(')
            ans = max(ans, ++opened);
        else if (c == ')')
            --opened;
        return ans;
    }
};

int main()
{
    cout<<"Enter the Expression : ";
    string str;
    getline(cin,str);
    Solution obj;
    cout<<obj.maxDepth(str);
}