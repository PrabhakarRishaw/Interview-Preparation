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
void levelwisetrasval(Node* root,int level,vector<vector<int>>&ans)
{
        if(root==NULL)
        {
            return;
        }
        if(ans.size() == level)
        {
           ans.push_back({});
        }
    ans[level].push_back(root->data);
    levelwisetrasval(root->left,level+1,ans);
    levelwisetrasval(root->right,level+1,ans);
}
vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>>ans;
    levelwisetrasval(root,0,ans);
    return ans;
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

    vector<vector<int>>res=levelOrder(root);

    for (vector<int> level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl; 
    }


}