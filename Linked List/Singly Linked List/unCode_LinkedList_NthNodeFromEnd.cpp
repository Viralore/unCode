//Program for getting the value of Nth node from the end of the linked list

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* nthNodeFromEnd(ListNode* head, int n) 
{
    if (head == NULL || n <= 0) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; ++i) 
    {
        if (fast == NULL) return NULL;
        fast = fast->next;
    }

    while (fast != NULL) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* result = nthNodeFromEnd(head, n);

    if (result != NULL) cout << "The " << n << "th node from the end is: " << result->val << endl;
    else cout << "List is shorter than " << n << " nodes." << endl;
    return 0;
}