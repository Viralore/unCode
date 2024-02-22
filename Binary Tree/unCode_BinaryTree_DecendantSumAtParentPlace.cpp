/*
    Replace node with its decendants sum
    Leave leaf nodes as 0
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int d)
    {
        data=d;
        right=left=nullptr;
    }
};

class Pair
{
    int sum;
    public:
    Pair(int l)
    {
        sum = l;
    }
    int getSum()
    {
        return sum;
    }
};

Pair replaceNodes(Node *root)
{
    if(root==nullptr)
    {
        Pair p(0);
        return p;
    }
    Pair L = replaceNodes(root->left);
    Pair R = replaceNodes(root->right);
    int c_sum = root->data + L.getSum() + R.getSum();
    root->data = L.getSum() + R.getSum();
    Pair p(c_sum);
    return p;
}

void postOrder(Node * root)
{
    if(root==nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    //Sample Input
    Node *root = new Node(5);
    Node *node1 = new Node(3);
    Node *node2 = new Node(1);
    Node *node3 = new Node(6);
    Node *node4 = new Node(4);
    Node *node5 = new Node(7);
    Node *node6 = new Node(2);
    Node *node7 = new Node(1);
    Node *node8 = new Node(8);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node6->left = node8;

    postOrder(root);
    Pair p = replaceNodes(root);
    cout<<endl;
    postOrder(root);
    return 0;
}
