//Program for splliting the singly linked list into 2 halves

#include <bits/stdc++.h>
using namespace std;


struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


void insertAtBeginning(ListNode*& head, int value) 
{
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}


void printList(ListNode* head) 
{
    ListNode* temp = head;
    while (temp != NULL) 
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


pair<ListNode*, ListNode*> splitList(ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return make_pair(head, nullptr);
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalfHead = slow->next;
    slow->next = NULL;

    return make_pair(head, secondHalfHead);
}

int main() 
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = NULL;
    for (int i = 5; i >= 1; --i) 
    {
        insertAtBeginning(head, i);
    }

    cout << "Original list: ";
    printList(head);

    pair<ListNode*, ListNode*> halves = splitList(head);
    cout << "First half: ";
    printList(halves.first);
    cout << "Second half: ";
    printList(halves.second);

    return 0;
}
