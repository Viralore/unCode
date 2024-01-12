//Program for deletion at last in Doubly Circular Linked List

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

// Function to insert a node at the beginning of a Doubly Circular Linked List
Node* insertAtStartDoublyCircular(Node* head, int x)
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
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        head = newNode;
    }

    return head;
}

// Function to delete the last node in a Doubly Circular Linked List
Node* deleteAtEndDoublyCircular(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }

    Node* temp = head;
    Node* last = head->prev;

    if (head->next == head)
    { // Only one node in the list
        delete temp;
        return nullptr;
    }

    last->prev->next = head;
    head->prev = last->prev;

    delete last;
    return head;
}



void printDoublyCircularLinkedList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Doubly Circular Linked List is empty." << endl;
        return;
    }
    Node* current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while (current != head);
    cout << endl;
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
        head = insertAtStartDoublyCircular(head, x);
    }

    cout << endl << "Printing all the Elements of Doubly Circular Linked List Before Deleting Last Node" << endl;
    printDoublyCircularLinkedList(head);

    cout << endl << "Printing all the Elements of Doubly Circular Linked List After Deleting Last Node" << endl;
    head = deleteAtEndDoublyCircular(head);
    printDoublyCircularLinkedList(head);
    return 0;
}
