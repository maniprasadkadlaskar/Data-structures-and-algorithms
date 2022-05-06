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

void rightView(Node * root) {
	if(root == NULL)
		return;

	queue <Node *> q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();

		for(int i=0;i < n;i++) {
			Node * curr = q.front();
			q.pop();

			if(i == n-1)
				cout<<curr->data<<endl;

			if(curr->left != NULL)
				q.push(curr->left);

			if(curr->right != NULL)
				q.push(curr->right);
		}
	}
}

void leftView(Node * root) {
	if(root == NULL)
		return;

	queue <Node *> q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();

		for(int i=0;i < n;i++) {
			Node * curr = q.front();
			q.pop();

			if(i == 0)
				cout<<curr->data<<endl;

			if(curr->left != NULL)
				q.push(curr->left);

			if(curr->right != NULL)
				q.push(curr->right);
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

	cout<<"Right View of Binary Tree"<<endl;
	rightView(root);
	cout<<endl;

	cout<<"Left View of Binary Tree"<<endl;
	leftView(root);
	cout<<endl;

    return 0;
}