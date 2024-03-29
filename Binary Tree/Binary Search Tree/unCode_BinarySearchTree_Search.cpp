// Program for Searching in Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Search Tree Node
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->data = val;
        this->left = this->right = nullptr;
    }
};

// Function to insert a value into a Binary Search Tree
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->data)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Function to perform inorder traversal of a Binary Search Tree
void inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

bool search(TreeNode *root,int key)
{
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(root->data>key) return search(root->left,key);
    if(root->data<key) return search(root->right,key);
    return false;
}

int main()
{
    TreeNode* root = nullptr;
    int n;

    cout << "Enter the number of elements to insert into the Binary Search Tree: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insertIntoBST(root, val);
    }

    cout << "Enter element for searching" << endl;
    int x;cin>>x;
    if(search(root,x)) cout<<"Element is present";
    else cout<<"Element is not present";
    return 0;
}

