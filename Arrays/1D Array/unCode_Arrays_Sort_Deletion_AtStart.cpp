//Program for deletion at the start of linked list
//Also used insertion at last
//We will use structure to create a linked list for this

//Time Complexity of Linear Search
//Worst Case    Average Case    Best Case
//O(1)            O(1)            O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node                         //Linked list in the form of nodes
{
    int data;                       //data field
    Node *next;                     //pointer field

    Node(int data)                  //creating a parameterized constructor
    {
        this->data = data;          //initialization of data field
        this->next = nullptr;       //setting pointer field to point to null
    }

};

void printLinkedList(Node *head)    //for printing we need a head pointer of the list
{
    Node *current = head;           //creating temporary var to store the head pointer contents to prevent loosing the list
    cout<<"List : ";                //because if anything happens to head we will lost the list so we need a temporary var
    while(current!=nullptr)         //loop till null pointer this means we reached the last of the list
    {                               //we start from head node till last node
        cout<<current->data<<" ";   //printing every node
        current = current->next;    //updating the current node NOTE- never forgot the updation of the pointer other wise infinite loop
    }
    cout<<endl;
}

//firstly we created a new node
//then if head is null then return that new node as head pointer
//created temp var to store head and traverse till last node
//then assign last node's next as new node to make it last node
//then return head pointer
Node *insertAtLast(Node *head,int x)
{
    Node *temp = new Node(x);       //created a temp var to create a node with data field as x
    if(head==nullptr) return temp;  //if head is null(or list is empty) then return temp as head
    Node *current = head;           //using temp var to prevent loss of list because using pointer it might happen
    while(current->next!=nullptr)   //traversing till last node
        current = current->next;
    current->next = temp;           //assigning the new node at last position
    return head;                    //returning head
}

//firstly created a temp var to store the node to be deleted
//then assigning the 2nd node to the head pointer
//deleting the temp var and return new head pointer
Node *deleteAtStart(Node *head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
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

    cout<<"Array Before Deletion"<<endl;                        //printing before deletion
    printLinkedList(head);

    cout<<"Deleting Element from start of Linked List"<<endl;   //deleting first element of linked list
    head = deleteAtStart(head);

    cout<<"Array After Deletion"<<endl;
    printLinkedList(head);
    return 0;
}
