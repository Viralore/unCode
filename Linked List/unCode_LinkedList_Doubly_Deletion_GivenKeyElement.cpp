//Program for deletion of a particular key element provided by user in Doubly Linked List

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

Node* deleteNodeByKey(Node* head, int key)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return nullptr;
    }

    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else
            {
                // If the key is in the first node, update the head
                head = current->next;
            }
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            delete current;
            return head;
        }
        current = current->next;
    }
    cout << "Key not found in the list." << endl;
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
    int key;
    cout << "Enter the key element to delete: ";
    cin >> key;

    head = deleteNodeByKey(head, key);
    cout << "Doubly Linked List after deleting the node with key " << key << ":" << endl;
    printDoublyLinkedList(head);
    return 0;
}
