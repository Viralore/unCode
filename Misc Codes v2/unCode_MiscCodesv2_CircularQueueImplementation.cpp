//Program of Circular Queue Implementations

#include <bits/stdc++.h>
using namespace std;

class CircularQueue 
{
private:
    int *arr;
    int size;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int capacity) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }

    ~CircularQueue() 
    {
        delete[] arr;
    }

    void enqueue(int item) 
    {
        if (isFull()) 
        {
            cout << "Queue is full. Enqueue operation failed." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        cout << "Enqueued: " << item << endl;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Dequeue operation failed." << endl;
            return -1;
        }

        int removedItem = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << "Dequeued: " << removedItem << endl;
        return removedItem;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Peek operation failed." << endl;
            return -1;
        }
        return arr[front];
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
    CircularQueue cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6); // Queue is full, will fail
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(6);
    cq.enqueue(7);
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue(); // Queue is empty, will fail
    return 0;
}
