//Program for searching in Linked List Doubly

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

void printDoublyLinkedList(Node* head)
{
    Node* current = head;
    cout << "Doubly Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool searchInDoublyLinkedList(Node* head, int x)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == x)
        {
            return true; // Element found
        }
        current = current->next;
    }
    return false; // Element not found
}

Node* insertAtEnd(Node* head, int x)
{
    Node* temp = new Node(x);
    if (head == nullptr)
    {
        return temp;
    }

    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = temp;
    temp->prev = current;
    return head;
}

int main()
{
    Node* head = nullptr;
    int N, x;
    cout << "Enter the number of elements in the Doubly Linked List: ";
    cin >> N;

    cout << endl << "Please Enter the elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the element " << (i + 1) << " : ";
        cin >> x;
        head = insertAtEnd(head, x);
    }

    cout << endl << "Printing all the Elements of Doubly Linked List" << endl;
    printDoublyLinkedList(head);

    cout << "Enter the element to search: ";
    cin >> x;

    if (searchInDoublyLinkedList(head, x))
    {
        cout << "Element " << x << " is present in the Doubly Linked List." << endl;
    }
    else
    {
        cout << "Element " << x << " is not present in the Doubly Linked List." << endl;
    }

    return 0;
}
