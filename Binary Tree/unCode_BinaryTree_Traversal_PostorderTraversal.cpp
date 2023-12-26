// Program for Postorder Traversal of Binary Tree

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

// Function to perform postorder traversal of a binary tree
void postorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);     // Traverse the left subtree
    postorderTraversal(root->right);    // Traverse the right subtree
    cout << root->data << " ";          // Visit the current node
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
    cout << "Postorder Traversal of the Binary Tree:" << endl;
    postorderTraversal(root);
    return 0;
}
