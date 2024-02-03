// Program for calculating height of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
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

// Function to perform inorder traversal of a binary tree
void inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);     // Traverse the left subtree
    cout << root->data << " ";        // Visit the current node
    inorderTraversal(root->right);    // Traverse the right subtree
}

// Function to get height of binary tree
int getHeight(TreeNode *root)
{
    if(root==nullptr) return 0;
    int n1 = getHeight(root->left);
    int n2 = getHeight(root->right);
    return max(n1,n2)+1;
}

// Function to create a sample binary tree
TreeNode* createSampleTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main()
{
    TreeNode* root = createSampleTree();
    cout<<"Height of the Binary Tree : "<<getHeight(root);
    return 0;
}
