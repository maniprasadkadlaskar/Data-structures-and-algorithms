#include<iostream>
#include<queue>
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

int height(Node * root) {
    if(root == NULL)
        return 0;

    return max(height(root->left),height(root->right)) + 1;
}

int maximum(Node * root) {
    if(root == NULL)
        return INT16_MIN;

    return max(root->data , max( maximum(root->left) , maximum(root->right) ));
}

int minimum(Node * root) {
    if(root == NULL)
        return INT16_MAX;

    return min(root->data , min( minimum(root->left) , minimum(root->right) ));
}

int size(Node * root) {
    if(root == NULL)
        return 0;

    return size(root->left) + size(root->right) + 1;
}

void levelOrderTraversal(Node * root) {
    if(root == NULL)
        return;

    queue <Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node * curr = q.front();
        q.pop();

        if(curr != NULL) {
            cout<<curr->data<<" ";

            if(curr->left != NULL)
                q.push(curr->left);

            if(curr->right != NULL)
                q.push(curr->right);
        } 
        else if(curr == NULL) {

            if(q.empty())
                return;

            q.push(NULL);
            cout<<endl;
        }
    }
}

int main() {
    Node * root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(1);
    root->left->left  = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(3);
    root->right->left->left = new Node(9);

    cout<<"Inorder Traversal of Binary Tree,"<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"Preorder Traversal of Binary Tree,"<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal of Binary Tree,"<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"Height of Binary Tree : "<<height(root)<<endl;

    cout<<"Maximum in Binary Tree : "<<maximum(root)<<endl;

    cout<<"Minimum in Binary Tree : "<<minimum(root)<<endl;

    cout<<"Size of Binary Tree : "<<size(root)<<endl;

    cout<<"Level Order Traversal Of Binary Tree......"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}