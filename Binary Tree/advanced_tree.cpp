#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int d;
    cout << "Enter node value (-1 for NULL): ";
    cin >> d;

    if (d == -1)
        return NULL;

    Node* root = new Node(d);

    cout << "Enter LEFT child of " << d << endl;
    root->left = buildTree();

    cout << "Enter RIGHT child of " << d << endl;
    root->right = buildTree();

    return root;
}

// Print parent of each node
void printParents(Node* root, Node* parent) {
    if (root == NULL)
        return;

    if (parent == NULL)
        cout << root->data << " -> NULL" << endl;
    else
        cout << root->data << " -> " << parent->data << endl;

    printParents(root->left, root);
    printParents(root->right, root);
}

// Print children of each node
void printChildren(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " -> ";
    if (root->left) cout << root->left->data << " ";
    if (root->right) cout << root->right->data << " ";
    cout << endl;

    printChildren(root->left);
    printChildren(root->right);
}

// Print leaf nodes
void printLeafNodes(Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Print degree of each node
void printDegrees(Node* root, Node* parent) {
    if (root == NULL)
        return;

    int degree = 0;
    if (root->left) degree++;
    if (root->right) degree++;
    if (parent != NULL) degree++;

    cout << root->data << " -> " << degree << endl;

    printDegrees(root->left, root);
    printDegrees(root->right, root);
}

int main() {
    Node* root = buildTree();

    cout << "\nParents of each node:\n";
    printParents(root, NULL);

    cout << "\nChildren of each node:\n";
    printChildren(root);

    cout << "\nLeaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "\nDegrees of nodes:\n";
    printDegrees(root, NULL);

    return 0;
}
