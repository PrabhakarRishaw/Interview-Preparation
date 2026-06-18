#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void InOrderTraversal(Node* root,vector<int>&ans)
{
        if(root==NULL)
        {
            return;
        }
        InOrderTraversal(root->left,ans);
        ans.push_back(root->data);
        InOrderTraversal(root->right,ans);
        return;
}
int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    // / \  /  \  / \
    //17 23 27 3  8  11

    Node* root = new Node(5);
    root->left=new Node(12);
    root->right=new Node(13);
    
    root->left->left=new Node(7);
    root->left->right=new Node(14);
    root->right->right=new Node(2);

    root->left->left->left=new Node(17);
    root->left->left->right=new Node(23);
    
    root->left->right->left=new Node(27);
    root->left->right->right=new Node(3);
    
    root->right->right->left=new Node(8);
    root->right->right->right=new Node(11);


    vector<int>ans;

    InOrderTraversal(root,ans);
       cout<<"The InOrder Traversal of Tree"<<endl;
        for (int val : ans) {
            cout << val << " ";
        }
        


}