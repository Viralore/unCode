// Program for linear search in Singly Circular Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

bool linearSearchCircular(Node* head, int key)
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

Node* insertAtEndCircular(Node* head, int x)
{
    Node* newNode = new Node(x);
    if (head == nullptr)
    {
        newNode->next = newNode;  // For the first node, point to itself.
        return newNode;
    }

    Node* current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
    return head;
}

int main()
{
    Node* head = nullptr;
    int N, x;
    cout << "Enter the number of elements in the Circular Linked List: ";
    cin >> N;

    cout << endl << "Please Enter the elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the element " << (i + 1) << " : ";
        cin >> x;
        head = insertAtEndCircular(head, x);
    }

    int key;
    cout << endl << "Enter the key to search: ";
    cin >> key;

    if (linearSearchCircular(head, key))
    {
        cout << "Key found in the Circular Linked List." << endl;
    } else {
        cout << "Key not found in the Circular Linked List." << endl;
    }
    return 0;
}
