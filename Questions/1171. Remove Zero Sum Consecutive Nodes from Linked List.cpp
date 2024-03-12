/*
1171. Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.
(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]

Constraints:
The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertNode(ListNode* head,int val)
{
    ListNode *new_node = new ListNode(val);
    if(head==nullptr) return new_node;
    ListNode* temp = head;
    while(temp->next!=nullptr)
        temp = temp->next;

    temp->next = new_node;
    return head;
}

class Solution
{
    public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode* ans = new ListNode(0, head);
        ListNode* start = ans;
        while(start != nullptr)
        {
            int prefix = 0;
            ListNode* end = start->next;
            while(end != nullptr)
            {
                prefix += end->val;
                if(prefix == 0)
                {
                    start->next = end->next;
                }
                end = end->next;
            }
            start = start->next;
        }
        return ans->next;
    }
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main()
{
    ListNode *head=nullptr;
    int val,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        head = insertNode(head,val);
    }
    printList(head);
    cout<<endl;
    Solution sol;
    ListNode *ans = sol.removeZeroSumSublists(head);
    printList(ans);
    return 0;
}
