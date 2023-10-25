//Program to reverse a Linked List
//We will use structure to create a linked list for this
//we used insertion at last operation to create a linked list

//Time Complexity of reversing a linked list
//Worst Case    Average Case    Best Case
//O(N)            O(N)            O(N)
//Space Complexity of reversing a linked list is O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node                         //Linked list in the form of nodes
{
    int data;                       //data field
    Node *link;                     //pointer field

    Node(int data)                  //creating a parameterized constructor
    {
        this->data = data;          //initialization of data field
        this->link = nullptr;       //setting pointer field to point to null
    }

};

void printLinkedList(Node *head)    //for printing we need a head pointer of the list
{
    Node *current = head;           //creating temporary var to store the head pointer contents to prevent loosing the list
    cout<<"List : ";                //because if anything happens to head we will lost the list so we need a temporary var
    while(current!=nullptr)         //loop till null pointer this means we reached the last of the list
    {                               //we start from head node till last node
        cout<<current->data<<" ";   //printing every node
        current = current->link;    //updating the current node NOTE- never forgot the updation of the pointer other wise infinite loop
    }
    cout<<endl;
}

Node *insertAtLast(Node *head,int x)
{
    Node *temp = new Node(x);       //created a temp var to create a node with data field as x
    if(head==nullptr) return temp;  //if head is null(or list is empty) then return temp as head
    Node *current = head;           //using temp var to prevent loss of list because using pointer it might happen
    while(current->link!=nullptr)   //traversing till last node
        current = current->link;
    current->link = temp;           //assigning the new node at last position
    return head;                    //returning head
}

Node *reverseLinkedList(Node *head)
{
    if(head==nullptr || head->link==nullptr) return head;   //if list is empty or only one node is present then return as it is
    Node *current = head, *prev=nullptr, *next=nullptr;     //defining variables to perform reverse operation
    while(current!=nullptr)                                 //loop till every node is not covered
    {
        next = current->link;                               //to store next node's address
        current->link = prev;                               //setting current nodes link part to previous node
        prev = current;                                     //setting previous node as current node
        current = next;                                     //to move to next node
    }
    return prev;                                            //returning previous as head because previous hold the new head as we reached to last node which is new node
}

int main()
{
    Node *head = nullptr;                                       //initialization of head pointer
    int N, x;                                                   //creating N for number of elements and x for insertion of elements
    cout<<"Enter number of elements in the Linked List : ";
    cin>>N;                                                     //taking input for N

    cout<<endl<<"Please Enter the elements"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the element "<<(i+1)<<" : ";
        cin>>x;                                                 //taking elements
        head = insertAtLast(head,x);                            //and inserting them at end of linked list
    }
    cout<<"List before reversing"<<endl;                        //printing the list before performing reverse operation
    printLinkedList(head);

    head = reverseLinkedList(head);                             //reversing the list
    cout<<"List after reversing"<<endl;                         //printing the list after performing reverse operation
    printLinkedList(head);
    return 0;
}
