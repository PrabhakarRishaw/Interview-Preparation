
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
int balancedTree(TreeNode* root,int left)
{
    if(root==NULL)
    {
        return 0;
    }
    int left = (root->left,left);

    return left;
}

int main()
{
    TreeNode* root = buildTree();
    cout << "\nInorder Traversal: ";
    InOrder(root);


}