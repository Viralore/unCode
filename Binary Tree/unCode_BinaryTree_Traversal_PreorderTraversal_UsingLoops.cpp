//Program for Preorder traversal using loops

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode *root)
{
    if (root == nullptr) return;
    stack<TreeNode *> st;
    TreeNode *current = root;
    while (current != nullptr || !st.empty())
    {
        while (current != nullptr)
        {
            cout << current->data << " ";
            st.push(current);
            current = current->left;
        }
        current = st.top()->right;
        st.pop();
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
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    return 0;
}
