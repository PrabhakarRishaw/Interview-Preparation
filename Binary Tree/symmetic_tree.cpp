/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int d;
    cout << "Enter value (-1 for NULL): ";
    cin >> d;

    if(d == -1)
    {
        return NULL;
    }

    Node* root = new Node(d);

    cout << "Enter left child of " << root->data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << root->data << endl;
    root->right = buildTree();

    return root;
}

void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

bool fun(Node* left, Node* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }

    if(left == NULL || right == NULL)
    {
        return false;
    }

    if(left->data != right->data)
    {
        return false;
    }

    return fun(left->left, right->right) &&
           fun(left->right, right->left);
}

bool isSymmetric(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    return fun(root->left, root->right);
}

int main()
{
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    InOrder(root);

    cout << endl;

    if(isSymmetric(root))
    {
        cout << "Tree is Symmetric";
    }
    else
    {
        cout << "Tree is Not Symmetric";
    }

    return 0;
}