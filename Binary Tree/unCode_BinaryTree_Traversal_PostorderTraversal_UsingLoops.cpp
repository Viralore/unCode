//Program for postorder traversal using loops

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void postorderTraversal(TreeNode *root)
{
    if (root == nullptr) return;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
        {
        TreeNode *current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left != nullptr) st1.push(current->left);
        if (current->right != nullptr) st1.push(current->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

TreeNode *buildTree()
{
    int d;
    cin >> d;
    if (d == -1) return nullptr;
    TreeNode *root = new TreeNode(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

/*
    How to give input
    example to create tree
             1
           /   \
          2     3
         / \   / \
        4   5 6   7

    then give input like this : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

int main()
{
    cout << "Enter the binary tree elements (preorder): ";
    TreeNode *root = buildTree();

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    return 0;
}
