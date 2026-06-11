/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
*/
#include<iostream>
#include<vector>
using namespace std;

//Creating Node 
struct TreeNode
{
    TreeNode* right;
    TreeNode* left;
    int val;
    TreeNode(int data)
    {
        this->val=data;
        right=NULL;
        left=NULL;
    }
};

// Building the Tree
TreeNode* buildTree()
{
    int d;
    cout << "Enter value (-1 for NULL): ";
    cin >> d;
    if(d == -1)
    {
        return NULL;
    }

    TreeNode* root = new TreeNode(d);

    cout << "Enter left child of " << root->val << endl;
    root->left = buildTree();

    cout << "Enter right child of " << root->val << endl;
    root->right = buildTree();

    return root;
}

void InOrder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->val<< " ";
    InOrder(root->right);
}
int maxDepth(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

int main()
{
    TreeNode* root = buildTree();
    cout << "\nInorder Traversal: ";
    InOrder(root);
    int maxdepth=maxDepth(root);
    cout<<maxdepth;

}