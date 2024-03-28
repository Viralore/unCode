#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* reverseList(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* reversedList = reverseList(head->next);
    head->next->prev = nullptr;
    head->next = nullptr;
    head->prev = reversedList;
    Node* temp = reversedList;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
    return reversedList;
}

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
        cin >> x;
        head = insertAtEnd(head, x);
    }
    cout << "Original list: ";
    printDoublyLinkedList(head);
    head = reverseList(head);
    cout << "Reversed list: ";
    printDoublyLinkedList(head);
    return 0;
}
