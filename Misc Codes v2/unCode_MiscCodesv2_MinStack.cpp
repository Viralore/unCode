//Min Stack, a stack that supports push, pop, top, and retrieving the minimum element in constant time. 

#include <bits/stdc++.h>
using namespace std;

class MinStack 
{
private:
    stack<int> s;
    stack<int> minStack;
    
public:
    MinStack() {}
    
    void push(int val) 
    {
        s.push(val);
        if (minStack.empty() || val <= minStack.top()) 
        {
            minStack.push(val);
        }
    }
    
    void pop() 
    {
        if (s.empty()) 
        {
            return;
        }
        if (s.top() == minStack.top()) 
        {
            minStack.pop();
        }
        s.pop();
    }
    
    int top() 
    {
        return s.top();
    }
    
    int getMin() 
    {
        return minStack.top();
    }
};

int main() 
{
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Minimum element: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;
    return 0;
}
