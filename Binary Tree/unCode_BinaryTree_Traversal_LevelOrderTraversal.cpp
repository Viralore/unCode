//Program for printing nodes in Level Order

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

void _levelOrderPrint(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *temp = q.front();
        if(temp==NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            cout<<temp->data<<" ";
        }
    }
}

int main()
{
    Node* root = buildTree();
    _levelOrderPrint(root);
    return 0;
}
