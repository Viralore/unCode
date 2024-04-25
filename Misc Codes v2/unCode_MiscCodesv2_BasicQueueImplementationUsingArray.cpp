//Program of basic implementation of queue using array

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

class Queue 
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() 
    {
        front = -1; // Initialize front to -1 to indicate an empty queue
        rear = -1;  // Initialize rear to -1 to indicate an empty queue
    }

    // Function to check if the queue is empty
    bool isEmpty() 
    {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() 
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow: Cannot enqueue element onto full queue." << endl;
            return;
        } 
        else if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    // Function to remove an element from the front of the queue
    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow: Cannot dequeue element from empty queue." << endl;
            return -1; // Return a default value indicating failure
        } 
        else if (front == rear) {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX_SIZE;
        }
        int dequeuedValue = arr[front];
        cout << "Dequeued " << dequeuedValue << " from the queue." << endl;
        return dequeuedValue;
    }

    // Function to return the front element of the queue without removing it
    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty." << endl;
            return -1; // Return a default value indicating failure
        }
        return arr[front];
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
    cout << "Front element after dequeuing: " << q.peek() << endl;
    return 0;
}