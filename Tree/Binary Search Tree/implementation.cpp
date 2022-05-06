#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root,int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left,val);
    }
    else {
        root->right = insert(root->right,val);
    }
    return root;
}

Node* search(Node* root, int key) {
    if(root == NULL)
        return NULL;
    
    if(root->data == key)
        return root;

    if(root->data > key)
        search(root->left,key);
    else
        search(root->right,key);
}

Node* maxValueNode(Node* root) {
    Node* curr = root;

    while(curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left,key);
    else if(key > root->data)
        root->right = deleteNode(root->right,key);
    else {
        if(root->left == NULL && root->right == NULL) {
           return NULL;
        }
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = maxValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root) {
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}


int main() {
    Node* root = NULL;
    root = insert(root,9);
    insert(root,3);
    insert(root,99);
    insert(root,46);
    insert(root,90);
    insert(root,6);
    inorder(root);
    cout<<endl;
    if(search(root,99))
        cout<<"Key Present"<<endl;
    else
        cout<<"Key Not Present"<<endl;

    deleteNode(root,3);
    deleteNode(root,99);

    if(search(root,99))
        cout<<"Key Present"<<endl;
    else
        cout<<"Key Not Present"<<endl;

    inorder(root);

    return 0;
}