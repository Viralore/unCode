//Program for insertion in Binary Tree in preorder manner

/*
    Sample input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
*/

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

//Preorder Build Tree
Node *buildTree()
{
    int d;
    cin>>d;
    if(d==-1) return NULL;
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node *root)
{
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = buildTree();
    preorder(root);
    return 0;
}
