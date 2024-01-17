//Program to find whether a loop is present in linked list or not
//We will use structure to create a linked list for this

//Time Complexity to find the loop
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

bool isLoopPresent(Node *head)
{
    if(head==nullptr || head->next==nullptr) return false;  //if list is empty or only node is there and point to null then return false
    Node *fast = head;                                      //fast pointer which will traverse at faster rate (2 nodes at a time)
    Node *slow = head;                                      //slow pointer which will traverse at slower rate (1 node at a time)
    while(fast!=nullptr && fast->next!=nullptr)             //loop till fast reaches till end
    {
        slow = slow->next;                                  //slow pointer updating to next node
        fast = fast->next->next;                            //fast pointer updating to next's next node
        if(slow==fast) return true;                         //if slow and fast meet then there is loop so return true
    }
    return false;                                           //if no loop is present(basically program counter reaches this point) then return false
}

int main()
{
    Node *head_1 = nullptr;
    Node *node_1 = new Node(1);     //creating Nodes
    Node *node_2 = new Node(2);
    Node *node_3 = new Node(3);
    Node *node_4 = new Node(4);
    Node *node_5 = new Node(5);
    Node *node_6 = new Node(6);
    Node *node_7 = new Node(7);
    Node *node_8 = new Node(8);
    Node *node_9 = new Node(9);

    head_1 = node_1;                  //linking the nodes
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_7;
    node_7->next = node_8;
    node_8->next = node_9;

    node_9->next = node_5;          //making the loop last node is linked to 5th node

    if(isLoopPresent(head_1)) cout<<"Loop is Present"<<endl;
    else cout<<"No Loop Present"<<endl;

    Node *head_2 = nullptr;         //making another head pointer having no loop
    head_2 = node_1;                //linking the nodes (using the same nodes)
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_7;
    node_7->next = node_8;
    node_8->next = node_9;
    node_9->next = nullptr;         //last node now points to the nullptr meaning no loop
    if(isLoopPresent(head_2)) cout<<"Loop is Present"<<endl;
    else cout<<"No Loop Present"<<endl;

    return 0;
}
