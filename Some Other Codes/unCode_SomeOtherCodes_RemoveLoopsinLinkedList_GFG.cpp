//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}


class Solution
{
    public:
    //Function to remove a loop in the linked list.
    bool haveLoop(Node* head)
    {
        if(head==NULL) return false;
        Node *s = head, *f = head;
        while(f!=NULL && f->next!=NULL)
        {
            f = f->next->next;
            s = s->next;
            if(f==s) return true;
        }
        return false;
    }
    
    bool isCircular(Node* head)
    {
        Node *s = head->next;
        for(int i=0;i<50;i++)
        {
            if(s==head) return true;
            s = s->next;
        }
        return false;
    }
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        bool chk = haveLoop(head);
        if(chk)
        {
            if(isCircular(head))
            {
                Node *s = head;
                for(int i=0;i<50;i++)
                {
                    if(s->next==head) break;
                    s = s->next;
                }
                s->next=NULL;
            }
            else
            {
                Node *s = head, *f = head;
                while(f!=NULL && f->next!=NULL)
                {
                    f = f->next->next;
                    s = s->next;
                    if(f==s) break;
                }
                f = head;
                while(f->next != s->next)
                {
                    f = f->next;
                    s = s->next;
                }
                s->next = NULL;
            }
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends