//Program for insertion at start of linked list Doubly
//We will use structure to create a linked list for this

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
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* insertAtBeginning(Node* head, int x)
{
    Node* temp = new Node(x);
    temp->next = head;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    return temp;
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
        head = insertAtBeginning(head, x);
    }
    cout << endl << "Printing all the Elements of Doubly Linked List" << endl;
    printDoublyLinkedList(head);

    return 0;
}
