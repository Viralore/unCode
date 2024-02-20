/*
    Maximum sum of subset of nodes given parent child condition
*/

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

class Pair
{
    int inc,exc;
    public:
    Pair(int inc,int exc)
    {
        this->inc = inc;
        this->exc = exc;
    }
    int getInc()
    {
        return inc;
    }
    int getExc()
    {
        return exc;
    }
};

Pair getMaxSum(Node *root)
{
    if(root==nullptr)
    {
        Pair p(0,0);
        return p;
    }
    Pair L = getMaxSum(root->left);
    Pair R = getMaxSum(root->right);
    int inc = root->data + L.getExc() + R.getExc();
    int exc = max(L.getInc(),L.getInc()) + max(R.getInc(),R.getInc());
    Pair p(inc,exc);
    return p;
}

int main()
{
    // Creating a sample tree
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Pair result = getMaxSum(root);
    cout << "Maximum sum of a subset of nodes: " << max(result.getInc(), result.getExc()) << endl;

    return 0;
}
