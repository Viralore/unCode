//Program to create singly linked list using vector

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedListFromVector(const vector<int>& vec) 
{
    if (vec.empty()) 
    {
        return nullptr;
    }

    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;

    for (size_t i = 1; i < vec.size(); ++i) 
    {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) 
{
    ListNode* current = head;
    while (current) 
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

int main() 
{
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedListFromVector(vec);

    printLinkedList(head);
    return 0;
}
