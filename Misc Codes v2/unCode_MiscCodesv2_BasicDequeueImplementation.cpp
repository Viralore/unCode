//Program of basic implemented double ended queue or dequeue


#include <bits/stdc++.h>
using namespace std;

class Deque 
{
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Deque(int capacity) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    void insertFront(int value) 
    {
        if (isFull()) 
        {
            cout << "Deque is full. Cannot insert at front.\n";
            return;
        }
        if (front == -1) 
        {
            front = rear = 0;
        } 
        else if (front == 0) 
        {
            front = capacity - 1;
        } 
        else 
        {
            front--;
        }
        arr[front] = value;
        size++;
    }

    void insertRear(int value) 
    {
        if (isFull()) 
        {
            cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }
        if (front == -1) 
        {
            front = rear = 0;
        } 
        else if (rear == capacity - 1) 
        {
            rear = 0;
        } 
        else 
        {
            rear++;
        }
        arr[rear] = value;
        size++;
    }

    void deleteFront() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else {
            if (front == capacity - 1) 
            {
                front = 0;
            } else {
                front++;
            }
        }
        size--;
    }

    void deleteRear() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else if (rear == 0) 
        {
            rear = capacity - 1;
        } 
        else 
        {
            rear--;
        }
        size--;
    }

    int getFront() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. No front element.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() 
    {
        if (isEmpty()) 
        {
            cout << "Deque is empty. No rear element.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    bool isFull() 
    {
        return size == capacity;
    }
};

int main() 
{
    Deque dq(5);
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.insertFront(4);
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;
    dq.deleteFront();
    dq.deleteRear();
    cout << "Front element after deletion: " << dq.getFront() << endl;
    cout << "Rear element after deletion: " << dq.getRear() << endl;
    return 0;
}
