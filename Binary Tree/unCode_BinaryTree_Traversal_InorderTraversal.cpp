// Program for Inorder Traversal of Binary Tree

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

// Function to create a sample binary tree
TreeNode* createSampleTree()
{
    // Sample Binary Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

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
    cout << "Inorder Traversal of the Binary Tree:" << endl;
    inorderTraversal(root);
    return 0;
}
