//Program for queue implementation using 2 stacks

#include <bits/stdc++.h>
using namespace std;

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

class Queue 
{
private:
    Node* front; 
    Node* rear;

public:
    Queue() 
    {
        front = rear = nullptr;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }

    void enqueue(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow: Cannot dequeue element from empty queue." << endl;
            return -1;
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        cout << "Dequeued " << dequeuedValue << " from the queue." << endl;
        return dequeuedValue;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1; 
        }
        return front->data;
    }
};

int main() 
{
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Front element after dequeueing: " << q.peek() << endl;
    return 0;
}
