//Program to delete duplicates in singly linked list

#include <bits/stdc++.h>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicates(ListNode* head) 
{
    if (head == nullptr) return nullptr;
    
    unordered_set<int> seen;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    
    while (curr != nullptr) 
    {
        if (seen.count(curr->val)) 
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } 
        else 
        {
            seen.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}


void printList(ListNode* head) 
{
    ListNode* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    
    cout << "Original list: ";
    printList(head);
    
    head = removeDuplicates(head);
    
    cout << "List after removing duplicates: ";
    printList(head);
    
    return 0;
}
