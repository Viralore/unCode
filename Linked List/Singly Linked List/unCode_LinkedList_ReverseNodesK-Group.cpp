//Program for Reversing the nodes in K-Groups

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseLinkedList(ListNode* head, int k) 
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (k--) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    int count = 0;
    ListNode* ptr = head;
    while (ptr != nullptr) 
    {
        count++;
        ptr = ptr->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while (count >= k) 
    {
        ListNode* start = prev->next;
        ListNode* end = start;
        for (int i = 1; i < k; ++i) 
        {
            end = end->next;
        }
        ListNode* nextGroup = end->next;
        
        end->next = nullptr;
        prev->next = reverseLinkedList(start, k);
        start->next = nextGroup;
        
        prev = start;
        count -= k;
    }
    
    return dummy.next;
}

void printList(ListNode* head) 
{
    while (head != nullptr) {
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
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 3;
    ListNode* result = reverseKGroup(head, k);

    cout << "Reversed list in k-group: ";
    printList(result);

    return 0;
}
