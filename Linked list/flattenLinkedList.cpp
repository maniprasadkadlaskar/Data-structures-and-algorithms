#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node * next, * down;
    Node(int val) {
        data = val;
        next = NULL;
        down = NULL;
    }
};

void display(Node * head) {
    Node * temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void flattenLinkedList(Node * &head) {
    if(head == NULL)
        return;

    Node * temp = NULL;
    Node * curr = head;
    Node * tail = head;

    while(tail->next != NULL)
        tail = tail->next;

    while(curr != tail) {
        if(curr->down != NULL) {
            tail->next = curr->down;
        
            temp = curr->down;
            while(temp->next != NULL)
                temp = temp->next;
            tail = temp;
        }
        curr = curr->next;
    }
}

int main() 
{
    Node * head = NULL;
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);    
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n8 = new Node(8);
    Node * n9 = new Node(9);

    head = n1;
    n1->next = n2;
    n1->down = n5;
    n2->next = n3;
    n3->next = n4;
    n3->down = n7;
    n5->next = n6;
    n6->down = n8;
    n8->next = n9;

    flattenLinkedList(head);
    display(head);
    
    return 0;
}