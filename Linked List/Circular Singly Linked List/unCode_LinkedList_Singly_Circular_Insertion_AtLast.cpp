//Program for insertion at last in Singly Circular Linked List

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

void printCircularLinkedList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
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

    cout << endl << "Printing all the Elements of Circular Linked List" << endl;
    printCircularLinkedList(head);

    return 0;
}
