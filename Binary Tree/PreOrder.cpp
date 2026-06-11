#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(vector<int> &preorder, int &i)
{
    if (i >= preorder.size() || preorder[i] == -1)
    {
        i++;
        return NULL;
    }

    Node *root = new Node(preorder[i]);
    i++;

    root->left = BuildTree(preorder, i);
    root->right = BuildTree(preorder, i);

    return root;
}

void PreOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    int i = 0;
    Node *root = BuildTree(preorder, i);

    cout << "Preorder Traversal: ";
    PreOrderTraversal(root);

    return 0;
}