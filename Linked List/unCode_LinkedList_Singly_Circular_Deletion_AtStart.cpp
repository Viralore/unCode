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
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while(current != head);
    cout << endl;
}

Node* insertAtStartCircular(Node* head, int x)
{
    Node* newNode = new Node(x);
    if (head == nullptr)
    {
        newNode->next = newNode;  // For the first node, point to itself.
    }
    else
    {
        Node* current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    return newNode;  // The new node becomes the new head.
}

Node* deleteFirstNodeCircular(Node* head)
{
    if (head == nullptr)
    {
        cout << "Circular Linked List is empty. Cannot delete." << endl;
        return nullptr;
    }

    Node* current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    Node* temp = head;
    if (head->next == head)
    {
        // If there is only one node in the circular linked list
        delete temp;
        return nullptr;  // Head becomes nullptr
    }

    current->next = head->next;  // Update the last node's next to skip the first node
    head = head->next;           // Update head to the next node
    delete temp;                 // Delete the first node
    return head;                 // Return the updated head
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
        head = insertAtStartCircular(head, x);
    }
    cout << endl << "Printing all the Elements of Circular Linked List" << endl;
    printCircularLinkedList(head);
    head = deleteFirstNodeCircular(head);
    cout << "After deleting the first node:" << endl;
    printCircularLinkedList(head);
    return 0;
}
