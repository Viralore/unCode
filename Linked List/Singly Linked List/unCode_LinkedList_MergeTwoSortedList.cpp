//Program to merge two sorted list

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) 
    {
        if (l1->val < l2->val) 
        {
            tail->next = l1;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) 
    {
        tail->next = l1;
    } 
    else 
    {
        tail->next = l2;
    }
    return dummy.next;
}

void printList(ListNode* head) 
{
    while (head) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* newNode(int val) 
{
    return new ListNode(val);
}

int main() 
{
    ListNode* l1 = newNode(1);
    l1->next = newNode(2);
    l1->next->next = newNode(4);

    ListNode* l2 = newNode(1);
    l2->next = newNode(3);
    l2->next->next = newNode(4);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
