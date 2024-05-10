//Program to evaluate Reverse Polish Notations

#include <bits/stdc++.h>
using namespace std;

int evaluateRPN(vector<string>& tokens) 
{
    stack<int> s;
    for (string& token : tokens) 
    {
        if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            if (token == "+") s.push(operand1 + operand2);
            else if (token == "-") s.push(operand1 - operand2);
            else if (token == "*") s.push(operand1 * operand2);
            else if (token == "/") s.push(operand1 / operand2);
        } 
        else 
        {
            s.push(stoi(token));
        }
    }
    return s.top();
}

int main() 
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << evaluateRPN(tokens) << endl;
    return 0;
}
