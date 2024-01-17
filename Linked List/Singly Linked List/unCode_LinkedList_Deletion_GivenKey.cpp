//Program for deletion of a node having a Key(Value)
//Also used insertion at last
//We will use structure to create a linked list for this

//Time Complexity of Deletion of Node having value(Key)
//Worst Case    Average Case    Best Case
//O(N)            O(N)            O(1)

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

//Modified Linear Search to find the key(value)
//it will return the address of the previous node to the node having the key
Node *modifiedLinearSearchInList(Node *head,int x)
{
    if(head==nullptr) return nullptr;       //if list is empty then return nullptr
    Node *current = head;                   //temp var to traverse the list
    Node *temp;                             //it will return the
    while(current!=nullptr)                 //loop till the last node
    {
        if(current->data==x) return temp;   //if found the key return true
        temp=current;                       //setting previous node address to the given node
        current = current->next;            //to reach to the next node
    }
    return nullptr;                         //return false if key not found
}

//Firstly checking whether the key is present or not in linked list
//if present then delete it
Node *deleteGivenKey(Node *head,int key,bool *status)
{
    if(head==nullptr) return nullptr;                                   //if list is empty then return nullptr
    if(head->data==key)                                                 //if key node is first node
    {
        if(head->next!=nullptr)                                         //if more than one node is present
        {
            Node *temp = head->next;                                    //setting temp var as second node
            delete head;                                                //delete head node
            *status = true;                                             //setting status as true
            return temp;                                                //returning temp as new head
        }
        else                                                            //if only one node is present
        {
            *status = true;                                             //setting status as true to tell head node is deleted
            return nullptr;                                             //returning nullptr as head is deleted
        }
    }
    Node *temp=nullptr;                                                 //temp var to find the node which is present just before the node having the value equal to key
    temp = modifiedLinearSearchInList(head,key);                        //temp var to to get (if key is present) the previous node
    if(temp!=nullptr)                                                   //if present then execute the if block
    {
        Node *temp_var = temp->next;                                    //storing the node having the key value to delete
        if(temp->next->next!=nullptr) temp->next = temp->next->next;    //if the node to deleted is not last node then assign the previous node's next to the next node of deleted node
        else temp->next=nullptr;                                        //if last node then previous node's next, make it null
        delete temp_var;                                                //delete the node
        *status = true;                                                 //this boolean will tell if operation is successful or not
        return head;                                                    //operation successful return head
    }
    return head;                                                        //return head but boolean value is false so not deletion
}

int main()
{
    Node *head = nullptr;                                               //initialization of head pointer as globally
    int N, x;                                                           //creating N for number of elements and x for insertion of elements
    cout<<"Enter number of elements in the Linked List : ";
    cin>>N;                                                             //taking input for N

    cout<<endl<<"Please Enter the elements"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the element "<<(i+1)<<" : ";
        cin>>x;                                                         //taking elements
        head = insertAtLast(head,x);                                    //and inserting them at end of linked list
    }
    cout<<"List Before Deletion"<<endl;                                 //printing list before deletion
    printLinkedList(head);

    cout<<"Enter a element to Delete : ";                               //taking input for the key to be deleted
    cin>>x;

    bool stat = false;                                                  //boolean value to check if key is present or not
    head = deleteGivenKey(head,x,&stat);                                //calling the delete function
    if(head==nullptr && stat==false) cout<<endl<<"List is empty"<<endl;                //if list is empty
    else if(!stat) cout<<endl<<"Key : "<<x<<" is not found"<<endl;      //if key not present
    else                                                                //key found and deleted successfully
    {
        cout<<endl<<"Key : "<<x<<" deleted successfully"<<endl;
        cout<<"List After Deletion"<<endl;                              //printing the list after successfully deletion of the key
        printLinkedList(head);
    }
    return 0;
}
