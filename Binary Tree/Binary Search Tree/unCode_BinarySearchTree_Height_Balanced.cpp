//Program for checking whether Tree is height balanced or not

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data = data;
        left=right=nullptr;
    }
};

//Helper Function
//Insert one single node in already created BST
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

//Will read entire input and create a BST
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

int getHeight(Node *root)
{
    if(root==nullptr) return 0;
    int n1 = getHeight(root->left);
    int n2 = getHeight(root->right);
    return max(n1,n2)+1;
}

//Optimization
class Pair
{
    int height;
    bool balanced;
    public:
    Pair(int h,bool b)
    {
        height=h;
        balanced=b;
    }
    int getH()
    {
        return height;
    }
    bool getB()
    {
        return balanced;
    }
};

Pair checkBalancedTree(Node *root)
{
    if(root==nullptr)
    {
        Pair p(0,true);
        return p;
    }
    Pair L = checkBalancedTree(root->left);
    Pair R = checkBalancedTree(root->right);
    int H = max(L.getH(),R.getH())+1;
    bool B = abs(L.getH() - R.getH()) <= 1 && L.getB() && R.getB();
    Pair p(H,B);
    return p;
}

int main()
{
    Node *root = NULL;
    cout<<"Enter elements for insertion '-1 to stop insertion'"<<endl;
    root = createBST();
    Pair p = checkBalancedTree(root);

    if(p.getB()) cout<<"Tree is balanced";
    else cout<<"Tree is not balanced";
    return 0;
}
