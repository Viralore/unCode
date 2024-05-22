//Program for flattening the multilevel doubly linked list
//Flattening a multilevel doubly linked list involves transforming a nested structure into a single-level linked list

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int value) : val(value), prev(nullptr), next(nullptr), child(nullptr) {}
};

class DoublyLinkedList 
{
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void addNode(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void printList(Node* head) 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* flatten(Node* head) 
    {
        if (!head) return nullptr;

        Node* current = head;
        stack<Node*> nodeStack;

        while (current) 
        {
            if (current->child) 
            {
                if (current->next) 
                {
                    nodeStack.push(current->next);
                }
                current->next = current->child;
                if (current->next) 
                {
                    current->next->prev = current;
                }
                current->child = nullptr;
            }

            if (!current->next && !nodeStack.empty()) 
            {
                current->next = nodeStack.top();
                nodeStack.pop();
                if (current->next) 
                {
                    current->next->prev = current;
                }
            }
            current = current->next;
        }

        return head;
    }
};

int main() 
{
    DoublyLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);

    Node* head = list.head;
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);

    cout << "Original list: ";
    list.printList(head);

    head = list.flatten(head);

    cout << "Flattened list: ";
    list.printList(head);

    return 0;
}
