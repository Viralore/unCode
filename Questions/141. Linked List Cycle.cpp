/*
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:
The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main()
{
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;

    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    head1 = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    ListNode *node_1 = new ListNode(1);
    ListNode *node_2 = new ListNode(2);
    head2 = node_1;
    node_1->next = node_2;

    cout<<"For List 1 : ";
    if(hasCycle(head1)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    cout<<"For List 2 : ";
    if(hasCycle(head2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    node_2->next = node_1;
    cout<<"For List 3 : ";
    if(hasCycle(head2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}
