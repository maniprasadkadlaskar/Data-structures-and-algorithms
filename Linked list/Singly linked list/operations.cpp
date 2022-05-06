#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node() {}
        Node(int val) {
            data = val;
            next = NULL;
        }
};

void insertathead(Node * &head,int val) {
    Node * n = new Node(val);
    n->next = head;
    head = n;
}

void insertattail(Node * &head,int val) {
    Node * n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }
    Node * temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteathead(Node * &head) {
    Node * deleteitem = head;
    head = head->next;
    delete deleteitem;
    return;
}

// void deletion(Node * &head,int val) {
//     Node * curr = head;
//     Node * prev = NULL;
//     if(head == NULL) {
//         return;
//     }
//     if(curr->data == val) {
//         head  = curr->next;
//         delete curr;
//         return;
//     }
//     while(curr != NULL && curr->data != val) {
//         prev = curr;
//         curr = curr->next;
//     }
//     if(curr == NULL)
//         cout<<"Element not present in list"<<endl;
//     else
//         {
//             prev->next = curr->next;
//             delete curr;
//         }
// }

void deletion(Node * &head,int pos) {
    Node * curr = head;
    Node * prev = NULL;
    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    if(pos == 0) {
        head  = curr->next;
        delete curr;
        return;
    }
    for(int i=0;i<pos;i++) {
        prev = curr;
        curr = curr->next;
        if(curr == NULL) {
            cout<<"Invalid Position"<<endl;
            return;
        }
    }
    prev->next = curr->next;
    delete curr;
}


void insert(Node * &head,int val,int pos) {
    Node * n = new Node(val);
    if(pos == 0) {
        n->next = head;
        head = n;
        return;
    }
    Node * temp = head;
    for(int i=1;i<pos-1;i++) {
        if(temp == NULL || temp->next == NULL) {
            cout<<"Invalid Position"<<endl;
            return;
        }
        temp = temp->next;
    }
    n->next = temp->next;
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
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);
    display(head);
    insert(head,0,6);
    display(head);
    deletion(head,4);
    display(head);
    return 0;
}