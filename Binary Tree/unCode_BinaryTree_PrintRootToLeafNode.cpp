//Program for Printing all nodes from Root - Leaf

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

//Function to print from Root to Leaf
void rootToLeafPath(Node *root,vector<int>& path)
{
    if(root==NULL)
    {
        return;
    }
    if(root->right==NULL && root->left==NULL)
    {
        for(auto node : path)
        {
            cout<<node<<" -> ";
        }
        cout<<root->data<<endl;
        return;
    }
    path.push_back(root->data);
    rootToLeafPath(root->left,path);
    rootToLeafPath(root->right,path);
    path.pop_back();
}

int main()
{
    Node* root = buildTree();
    vector<int> path;
    rootToLeafPath(root,path);
    return 0;
}
