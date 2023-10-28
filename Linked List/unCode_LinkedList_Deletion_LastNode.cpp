//Program for deletion of last node in linked list
//We will use structure to create a linked list for this

//Time Complexity of deletion at last
//Worst Case    Average Case    Best Case
//O(N)            O(N)            O(N)

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

//In this we created 2 variables one to traverse till last node and one to point the second last node
//we traverse till last node then delete it and return head pointer
Node *deleteAtLast(Node *head)
{
    if(head==nullptr || head->next==nullptr) return nullptr;    //if list is empty or only one node is present then return null
    Node *current = head;                                       //temp var to traverse till last node
    Node *pre = nullptr;                                        //temp var to point the second last node
    while(current->next!=nullptr)                               //loop till last node
    {
        pre = current;                                          //point the current pointer
        current = current->next;                                //to move to the next node
    }
    pre->next=nullptr;                                          //removing the link of second last node with last node
    delete current;                                             //deleting the last node
    return head;                                                //returning the head pointer
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

    cout<<endl<<"Printing List before deletion of last node"<<endl;
    printLinkedList(head);                                      //printing the elements

    if(head==nullptr) cout<<"List is already empty"<<endl;      //if list is empty
    else
    {
        cout<<"Deleting the last node"<<endl;
        head = deleteAtLast(head);                              //deleting the last node
        if(head==nullptr) cout<<"Now list is empty after deletion"<<endl;  //if after deletion list become empty
        else
        {
            cout<<endl<<"Printing List after the deletion of last node"<<endl;
            printLinkedList(head);                                      //printing the elements
        }
    }
    return 0;
}
