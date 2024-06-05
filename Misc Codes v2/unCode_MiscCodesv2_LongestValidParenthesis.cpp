//Program to find the length of longest valid parenthesis

#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) 
{
    stack<int> stk;
    stk.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == '(') 
        {
            stk.push(i);
        } 
        else 
        {
            stk.pop();
            if (stk.empty()) 
            {
                stk.push(i);
            } 
            else 
            {
                maxLength = max(maxLength, i - stk.top());
            }
        }
    }

    return maxLength;
}

int main() 
{
    string s = "(()))())(";
    cout << "Longest Valid Parentheses: " << longestValidParentheses(s) << endl;
    return 0;
}
