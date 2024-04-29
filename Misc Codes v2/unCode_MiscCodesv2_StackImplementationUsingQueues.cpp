//Program for stack implementation using queues

#include <bits/stdc++.h>
using namespace std;

class MyStack 
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    
    void push(int x) 
    {
        while (!q1.empty()) 
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);
        
        while (!q2.empty()) 
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    
    int pop() 
    {
        if (empty()) 
        {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        int top = q1.front();
        q1.pop();
        return top;
    }

    
    int top() 
    {
        if (empty()) 
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q1.front();
    }

    
    bool empty() 
    {
        return q1.empty();
    }
};

int main() 
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    return 0;
}
