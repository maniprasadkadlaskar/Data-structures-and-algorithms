#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

class MyStack : public Node {
    public:
        Node * head;
        int Size;
        MyStack() {
            head = NULL;
            Size = 0;
        }
        void push(int Data) {
            Node * temp = new Node();
            temp->data = Data;
            temp->next = head;
            head = temp;
            Size ++;
        }

        int peek() {
            int temp = head->data;
            return temp; 
        }

        int pop() {
            int temp = head->data;
            Node * deletenode = head;
            head = head->next;
            Size --;
            delete deletenode;
            return temp;
        }

        int size() {
            return Size;
        }

        bool isempty() {
            return head == NULL;
        }

        void displayStack();
        ~MyStack();
};

MyStack :: ~MyStack() {
    while(head != NULL) {
        Node * temp = head;
        head = head->next; 
        delete temp;
    }
    
}

void MyStack :: displayStack() {
    Node * temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

int main() {
    MyStack * s = new MyStack();
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(7);
    cout<<"Items in stack are,"<<endl;
    s->displayStack();
    cout<<"Is Stack empty : "<<s->isempty()<<endl;
    cout<<"Popped item is : "<<s->pop()<<endl;
    cout<<"Items in stack are,"<<endl;
    s->displayStack();
    cout<<"Top item is : "<<s->peek()<<endl;
    cout<<"Size of Stack : "<<s->size()<<endl;
    return 0;
}