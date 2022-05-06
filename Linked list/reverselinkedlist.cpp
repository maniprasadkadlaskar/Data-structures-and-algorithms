#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node() {}
        Node(int val) {
            data = val;
            next = NULL;
        }
};

void insert(Node * &head,int val) {
    Node * n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    Node * temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

Node *  reverse(Node * &head) {
    Node * curr = head;
    Node * prev = NULL;
    while(curr != NULL) {
        Node * temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void display(Node * head) {
    Node * temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node * head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    cout<<"Before reversing : ";
    display(head);
    head = reverse(head);
    cout<<"After reversing : ";
    display(head);
    return 0;
}