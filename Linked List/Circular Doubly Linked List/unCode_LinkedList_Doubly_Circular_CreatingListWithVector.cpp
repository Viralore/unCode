//Program to create list with vector

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

ListNode* createDoublyCircularLinkedListFromVector(const vector<int>& vec) 
{
    if (vec.empty()) 
    {
        return nullptr;
    }

    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;

    for (size_t i = 1; i < vec.size(); ++i) 
    {
        ListNode* newNode = new ListNode(vec[i]);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }

    current->next = head;
    head->prev = current;

    return head;
}

void printDoublyCircularLinkedList(ListNode* head) 
{
    if (head == nullptr) 
    {
        cout << "The list is empty." << endl;
        return;
    }

    ListNode* current = head;
    do 
    {
        cout << current->val << " <-> ";
        current = current->next;
    } 
    while (current != head);
    cout << "(head)" << endl;
}

int main() 
{
    vector<int> vec = {1, 2, 3, 4, 5};

    ListNode* head = createDoublyCircularLinkedListFromVector(vec);

    cout << "Doubly Circular Linked List:" << endl;
    printDoublyCircularLinkedList(head);
    return 0;
}
