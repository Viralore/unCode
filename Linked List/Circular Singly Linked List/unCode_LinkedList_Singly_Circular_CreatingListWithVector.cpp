//Program for creating list with vector

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createCircularLinkedListFromVector(const vector<int>& vec) 
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
        current = current->next;
    }

    current->next = head;

    return head;
}

void printCircularLinkedList(ListNode* head) 
{
    if (head == nullptr) 
    {
        cout << "The list is empty." << endl;
        return;
    }

    ListNode* current = head;
    do 
    {
        cout << current->val << " -> ";
        current = current->next;
    } 
    while (current != head);
    cout << "(head)" << endl;
}

int main() 
{
    vector<int> vec = {1, 2, 3, 4, 5};

    ListNode* head = createCircularLinkedListFromVector(vec);

    cout << "Singly Circular Linked List:" << endl;
    printCircularLinkedList(head);
    return 0;
}
