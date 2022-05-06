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

Node *  reverse(Node * &mid) {
    Node * curr = mid;
    Node * prev = NULL;
    while(curr != NULL) {
        Node * temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node * midpointer(Node * head) {
    Node * fast = head;
    Node * slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool palindrom(Node * &head) {
    if(head == NULL)
        return true;
    Node * mid = midpointer(head);
    Node * tail = reverse(mid);
    Node * curr = head;
    while (tail != NULL) {
        if(curr ->data != tail ->data)
            return false;
        tail = tail->next;        
        curr = curr->next;
   
    }
    return true;
}

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
    insert(head,2);
    insert(head,1);
    display(head);
    if(palindrom(head))
        cout<<"Is Palindrom"<<endl;
    else
        cout<<"Not Palindrom"<<endl;
    return 0;
} 