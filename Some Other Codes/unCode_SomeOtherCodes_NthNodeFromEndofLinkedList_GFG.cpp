//Problem link : https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/0

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);


//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
       // Your code here
        int count=0,last;
        Node *curr = head;
        while(curr!=NULL)
        {
            count++;
            if(curr->next==NULL) last = curr->data;
            curr = curr->next;
        }
        if(n>count) return -1;
        int diff = count-n;
        curr = head;
        for(int i=0;i<diff;i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
};

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}