//Program for Reversal of Doubly Linked List

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

void printDoublyLinkedList(Node* head) {
    Node* current = head;
    cout << "Doubly Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* insertAtEnd(Node* head, int x)
{
    Node* newNode = new Node(x);
    if (head == nullptr)
    {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* reverseDoublyLinkedList(Node* head)
{
    Node* prevNode = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        Node* nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        prevNode = current;
        current = nextNode;
    }
    return prevNode;
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
    head = reverseDoublyLinkedList(head);
    cout << "Doubly Linked List after reversal:" << endl;
    printDoublyLinkedList(head);
    return 0;
}
