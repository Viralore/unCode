//Program for reversing the linked list using recursion

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *insertAtLast(Node *head,int x)
{
    Node *temp = new Node(x);
    if(head==nullptr) return temp;
    Node *current = head;
    while(current->next!=nullptr)
        current = current->next;
    current->next = temp;
    return head;
}

Node* reverseList(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* reversedList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reversedList;
}

void printList(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;
    int n,x;
    cout<<"Enter no. of elements : ";cin>>n;
    cout<<"Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = insertAtLast(head,x);
    }
    cout<<endl;
    cout << "Original list: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed list: ";
    printList(head);
    return 0;
}
