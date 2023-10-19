//Program for insertion at start of linked list
//We will use structure to create a linked list for this

//Time Complexity of insertion at start
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
//then assigning node's next as head and returning new node as head pointer
Node *insertAtBeginning(Node *head,int x)
{
    Node *temp = new Node(x);       //created a temp var to create a node with data field as x
    temp->next = head;              //making temp var as head pointer
    return temp;                    //returning temp as head pointer
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
        head = insertAtBeginning(head,x);                       //and inserting them at start of linked list
    }

    cout<<endl<<"Printing all the Elements of Linked List"<<endl;
    printLinkedList(head);                                      //printing the elements

    return 0;
}
