//Implementation of Dequeue using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) 
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Deque 
{
private:
    Node* front;
    Node* rear;

public:
    Deque() 
    {
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        Node* temp = front;
        if (front == rear) 
        {
            front = rear = nullptr;
        } 
        else 
        {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    void deleteRear() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        Node* temp = rear;
        if (front == rear) 
        {
            front = rear = nullptr;
        } 
        else
        {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    int getFront() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. No front element.\n";
            return -1;
        }
        return front->data;
    }

    int getRear() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. No rear element.\n";
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() 
    {
        return front == nullptr && rear == nullptr;
    }
};

int main() 
{
    Deque dq;
    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertRear(3);
    dq.insertRear(4);
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;
    dq.deleteFront();
    dq.deleteRear();
    cout << "Front element after deletion: " << dq.getFront() << endl;
    cout << "Rear element after deletion: " << dq.getRear() << endl;
    return 0;
}
