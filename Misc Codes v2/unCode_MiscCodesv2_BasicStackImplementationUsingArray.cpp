#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() 
    {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    // Function to check if the stack is empty
    bool isEmpty() 
    {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int value) 
    {
        if (top >= MAX_SIZE - 1) 
        {
            cout << "Stack Overflow: Cannot push element onto full stack." << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow: Cannot pop element from empty stack." << endl;
            return -1; // Return a default value indicating failure
        }
        int poppedValue = arr[top--];
        cout << "Popped " << poppedValue << " from the stack." << endl;
        return poppedValue;
    }

    // Function to return the top element of the stack without removing it
    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty." << endl;
            return -1; // Return a default value indicating failure
        }
        return arr[top];
    }
};

int main() 
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.pop();
    cout << "Top element after popping: " << s.peek() << endl;
    s.pop();
    s.pop(); // Trying to pop from an empty stack
    return 0;
}
