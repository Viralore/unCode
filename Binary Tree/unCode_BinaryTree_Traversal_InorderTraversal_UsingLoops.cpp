#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Build tree in preorder fashion
TreeNode *buildTree()
{
    int data;
    cin>>data;
    if(data==-1) return NULL;
    TreeNode *root = new TreeNode(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->val << " ";
        current = current->right;
    }
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
    TreeNode* root = buildTree();
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
