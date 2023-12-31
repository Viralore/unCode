//Program for deletion of last node in Doubly Linked List

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

Node* deleteLastNode(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return nullptr;
    }

    if (head->next == nullptr)
    {
        // Only one node in the list
        delete head;
        return nullptr;
    }

    Node* current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
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
    head = deleteLastNode(head);
    cout << "Doubly Linked List after deleting the last node:" << endl;
    printDoublyLinkedList(head);
    return 0;
}
