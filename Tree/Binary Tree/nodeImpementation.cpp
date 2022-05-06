#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * left, * right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node * createTree() {
    int val;
    cout<<"Enter data : "<<endl;
    cin>>val;

    if(val == -1)
        return NULL;

    Node *root = new Node(val);
    cout<<"Enter left for "<<val<<endl;
    root->left = createTree();
    cout<<"Enter right for "<<val<<endl;
    root->right = createTree();

    return root;
}

void inorderTraversal(Node * root) {
    if(root == NULL)
        return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node * root) {
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node * root) {
    if(root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node * root = createTree();
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    return 0;
}