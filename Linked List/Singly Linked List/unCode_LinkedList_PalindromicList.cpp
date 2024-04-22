//Program for checking whether given linked list is Palindromic or not

#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
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
    while (temp != nullptr) 
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


ListNode* findMiddle(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


ListNode* reverseList(ListNode* head) 
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) 
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


bool isPalindrome(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return true;
    }

    ListNode* middle = findMiddle(head);

    ListNode* secondHalf = reverseList(middle->next);

    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    while (p2 != nullptr) 
    {
        if (p1->val != p2->val) 
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main() 
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = nullptr;
    for (int i : {1, 2, 3, 2, 1}) 
    {
        insertAtBeginning(head, i);
    }

    cout << "Original list: ";
    printList(head);

    if (isPalindrome(head)) cout << "The linked list is a palindrome." << endl;
    else cout << "The linked list is not a palindrome." << endl;
    
    return 0;
}
