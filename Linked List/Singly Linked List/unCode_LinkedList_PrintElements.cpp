//Program to create and print the Linked List
//We will use structure to create a linked list for this

//Time Complexity of Printing the list
//Worst Case    Average Case    Best Case
//O(N)          O(N)          O(N)
//Space Complexity of Printing the list is O(1)

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

int main()
{
    Node *head = nullptr;           //initialization of head pointer
    Node *node_1 = new Node(1);     //creating nodes
    Node *node_2 = new Node(2);
    Node *node_3 = new Node(3);
    Node *node_4 = new Node(4);
    Node *node_5 = new Node(5);

    head = node_1;                  //linking all the nodes
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;

    printLinkedList(head);          //printing the linked list

    return 0;
}
