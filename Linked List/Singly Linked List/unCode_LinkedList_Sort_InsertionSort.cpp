//Program for insertion sort on singly linked list

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

ListNode* insertionSort(ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }

    ListNode* sortedHead = NULL; 
    ListNode* curr = head; 

    while (curr != NULL) 
    {
        ListNode* nextNode = curr->next; 

        if (sortedHead == NULL || curr->val <= sortedHead->val) 
        {
            curr->next = sortedHead;
            sortedHead = curr;
        } 
        else 
        {
            ListNode* temp = sortedHead;
            while (temp->next != NULL && temp->next->val < curr->val) 
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = nextNode;
    }

    return sortedHead;
}

int main() 
{
    // Create a sample linked list: 5 -> 3 -> 7 -> 2 -> 6
    ListNode* head = NULL;
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 7);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 5);

    cout << "Original list: ";
    printList(head);

    head = insertionSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
