//Program for Finding the diameter

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

int getHeight(Node *root)
{
    if(root==nullptr) return 0;
    int n1 = getHeight(root->left);
    int n2 = getHeight(root->right);
    return max(n1,n2)+1;
}

class Pair
{
    int height, diameter;
    public:
    Pair(int H,int d)
    {
        this->height = H;
        this->diameter=d;
    }
    int getH()
    {
        return height;
    }
    int getD()
    {
        return diameter;
    }
};

//O(N)
Pair getDiameter(Node *root)
{
    if(root==nullptr)
    {
        Pair P(0,0);
        return P;
    }
    Pair L = getDiameter(root->left);
    Pair R = getDiameter(root->right);
    int h = max(L.getH(),R.getH()) +1;
    int d = max(L.getH()+R.getH(),max(L.getD(),R.getD()));
    Pair p(h,d);
    return p;
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(7);

    // Calling the getDiameter function
    Pair result = getDiameter(root);

    // Printing the result
    cout << "Diameter of the binary tree: " << result.getD() << endl;

    return 0;
}
