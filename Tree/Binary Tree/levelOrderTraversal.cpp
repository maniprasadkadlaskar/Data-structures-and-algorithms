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

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();

        if (root->left != nullptr)
            q.push(root->left);

        if (root->right != nullptr)
            q.push(root->right);

        cout << root->data << " ";

        q.pop();
    }
}

    int main()
    {
        Node *root = new Node(2);
        root->left = new Node(4);
        root->right = new Node(1);
        root->left->left = new Node(7);
        root->right->left = new Node(8);
        root->right->right = new Node(3);
        root->right->left->left = new Node(9);

        cout << "Level order traversal of Binary Tree" << endl;
        levelOrder(root);
        cout << endl;

        return 0;
    }