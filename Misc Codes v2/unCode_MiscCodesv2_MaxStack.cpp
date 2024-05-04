//Max Stack, a stack that supports push, pop, top, and retrieving the maximum element in constant time. 

#include <bits/stdc++.h>
using namespace std;

class MaxStack {
private:
    stack<int> s;
    stack<int> maxStack;
    
public:
    MaxStack() {}
    
    void push(int val) 
    {
        s.push(val);
        if (maxStack.empty() || val >= maxStack.top()) 
        {
            maxStack.push(val);
        }
    }
    
    void pop() 
    {
        if (s.empty()) 
        {
            return;
        }
        if (s.top() == maxStack.top()) 
        {
            maxStack.pop();
        }
        s.pop();
    }
    
    int top() 
    {
        return s.top();
    }
    
    int getMax() 
    {
        return maxStack.top();
    }
};

int main() 
{
    MaxStack maxStack;

    maxStack.push(3);
    maxStack.push(1);
    maxStack.push(5);
    
    cout << "Maximum element: " << maxStack.getMax() << endl;
    maxStack.pop();
    cout << "Top element: " << maxStack.top() << endl;
    cout << "Maximum element: " << maxStack.getMax() << endl;
    return 0;
}
