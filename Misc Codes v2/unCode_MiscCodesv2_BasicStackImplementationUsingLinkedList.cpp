//Program of stack implemented using linked list

#include<bits/stdc++.h>
using namespace std;

// Definition of a node in the linked list
class Node 
{
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

class Stack 
{
private:
    Node* top;

public:
    Stack() 
    {
        top = nullptr;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty()) 
        {
            top = newNode;
        } 
        else 
        {
            newNode->next = top;
            top = newNode;
        }
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow: Cannot pop element from empty stack." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped " << poppedValue << " from the stack." << endl;
        return poppedValue;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return top->data;
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
    return 0;
}
