// Program for linear search in Doubly Circular Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to insert a node at the end of a Doubly Circular Linked List
Node* insertAtEndDoublyCircular(Node* head, int x)
{
    Node* newNode = new Node(x);

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    return head;
}

// Function to perform linear search in Doubly Circular Linked List
bool linearSearchDoublyCircular(Node* head, int key)
{
    if (head == nullptr)
    {
        return false;  // List is empty
    }

    Node* current = head;
    do
    {
        if (current->data == key)
        {
            return true;  // Key found
        }
        current = current->next;
    }
    while (current != head);

    return false;  // Key not found
}

int main()
{
    Node* head = nullptr;
    int N, x;
    cout << "Enter the number of elements in the Doubly Circular Linked List: ";
    cin >> N;

    cout << endl << "Please Enter the elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the element " << (i + 1) << " : ";
        cin >> x;
        head = insertAtEndDoublyCircular(head, x);
    }

    int key;
    cout << endl << "Enter the key to search: ";
    cin >> key;

    if (linearSearchDoublyCircular(head, key))
    {
        cout << "Key found in the Doubly Circular Linked List." << endl;
    }
    else
    {
        cout << "Key not found in the Doubly Circular Linked List." << endl;
    }
    return 0;
}
