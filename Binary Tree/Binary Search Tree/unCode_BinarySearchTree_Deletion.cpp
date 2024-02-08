//Program for deletion in Binary Search Tree

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

Node *insert(Node *root,int key)
{
    if(root==NULL)
    {
        return new Node(key);
    }
    if(key<root->data)
    {
        root->left = insert(root->left,key);
    }
    else root->right = insert(root->right,key);

    return root;
}

Node * createBST()
{
    int data;
    cin>>data;
    Node *root = NULL;
    while(data!=-1)
    {
        root = insert(root,data);
        cin>>data;
    }

    return root;
}

bool searchInTree(Node *root,int key)
{
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(root->data>key) return searchInTree(root->left,key);
    if(root->data<key) return searchInTree(root->right,key);
}

Node *remove(Node *root,int key)
{
    if(root==NULL);
    if(root->data == key)
    {
        //case 0 -> no child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        //case 1 -> 1 child
        else if(root->left!=NULL && root->right==NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //case 2 -> 2 child
        else
        {
            Node *temp = root->right;
            while(temp->left!=NULL)
            {
                temp = temp->left;
            }
            //overwrite the root data with next data
            root->data = temp->data;
            //delete the next value from the right subtree
            root->right = remove(root->right,temp->data);
            return root;
        }
    }
    else if(root->data>key)
    {
        root->left = remove(root->left,key);
    }
    else
    {
        root->right = remove(root->right,key);
    }
    return root;
}

void inorderTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

//Sample Input : 5 4 6 3 7 2 8 1 9 10 -1 for creating tree
int main()
{
    cout<<"Nodes : ";
    Node *root = createBST();
    int key;
    cout<<"Inorder Traversal : ";
    inorderTraversal(root);
    cout<<endl<<"Enter element to delete : ";
    cin>>key;
    if(searchInTree(root,key))
    {
        root = remove(root,key);
        cout<<endl<<"After deletion inorder traversal : ";
        inorderTraversal(root);
    }
    return 0;
}
