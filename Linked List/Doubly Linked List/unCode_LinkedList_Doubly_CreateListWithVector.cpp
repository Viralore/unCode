//Program to create list from vector

#include <bits/stdc++.h>
using namespace std;

struct DoublyListNode 
{
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

DoublyListNode* createDoublyLinkedListFromVector(const vector<int>& vec) 
{
    if (vec.empty()) 
    {
        return nullptr;
    }

    DoublyListNode* head = new DoublyListNode(vec[0]);
    DoublyListNode* current = head;

    for (size_t i = 1; i < vec.size(); ++i) 
    {
        DoublyListNode* newNode = new DoublyListNode(vec[i]);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }
    return head;
}

void printDoublyLinkedList(DoublyListNode* head) 
{
    DoublyListNode* current = head;
    while (current) 
    {
        cout << current->val << " <-> ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() 
{
    vector<int> vec = {1, 2, 3, 4, 5};
    DoublyListNode* head = createDoublyLinkedListFromVector(vec);

    cout << "Doubly Linked List:" << endl;
    printDoublyLinkedList(head);
    return 0;
}
