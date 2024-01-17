//Program for insertion at last of linked list (Efficient)
//We will use structure to create a linked list for this

//Time Complexity of insertion at last (Efficient)
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

Node *last_Node_Address = nullptr;      //we will use a pointer to point to the last node

//firstly we created a new node
//then if head is null then return that new node as head pointer
//created temp var to store head and traverse till last node
//then assign last node's next as new node to make it last node
//then return head pointer
Node *insertAtLastEfficient(Node *head,int x)
{
    Node *temp = new Node(x);               //new node created o be inserted
    if(head==nullptr)                       //when list is empty
    {
        head = temp;                        //making the new node as head
        last_Node_Address = head;           //updating the last node pointer
        return head;                        //returning head
    }
    last_Node_Address->next = temp;         //we have last node address so directly assigning the next pointer to the newly created node
    last_Node_Address = temp;               //updating the last node pointer to the new node
    return head;                            //returning the head
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
        head = insertAtLastEfficient(head,x);                            //and inserting them at end of linked list
    }

    cout<<endl<<"Printing all the Elements of Linked List"<<endl;
    printLinkedList(head);                                      //printing the elements

    return 0;
}
