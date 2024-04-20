//Program for merge sort on singly Linked List

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
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != NULL && l2 != NULL) 
    {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) 
    {
        tail->next = l1;
    } 
    else 
    {
        tail->next = l2;
    }

    return dummy.next;
}


ListNode* findMiddle(ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* mergeSort(ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }

    ListNode* mid = findMiddle(head);
    ListNode* midNext = mid->next;
    mid->next = NULL;

    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(midNext);

    return merge(left, right);
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
    head = mergeSort(head);
    cout << "Sorted list: ";
    printList(head);
    return 0;
}
