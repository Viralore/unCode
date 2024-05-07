/*
2487. Remove Nodes From Linked List

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 
Constraints:
The number of the nodes in the given list is in the range [1, 10^5].
1 <= Node.val <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode* curr = head;
        deque<ListNode*> dq;
        while(curr!=nullptr)
        {
            if(!dq.empty())
            {
                while(!dq.empty() && dq.back()->val < curr->val)
                {
                    dq.pop_back();
                }
            }
            dq.push_back(curr);
            curr = curr->next;
        }
        ListNode* ans = dq.front();
        ListNode* temp = ans;
        dq.pop_front();
        while(!dq.empty())
        {
            temp->next = dq.front();
            temp = temp->next;
            dq.pop_front();
        }
        return ans;
    }
};