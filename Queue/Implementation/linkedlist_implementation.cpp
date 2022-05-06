#include<iostream>
using namespace std;

class Node {
    public :
    int data;
    Node * next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    public :
    Node * front;
    Node * rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    void push(int ele) {
        Node * n = new Node(ele);

        if(front == NULL) {
            front = n;
            rear = n;
        }
        rear->next = n;
        rear = n;
    }

    void pop() {
        if(front == NULL) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node * deletenode = front;
        front = front->next;
        delete deletenode;
    }

    int peek() {
        if(front == NULL) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty() {
        if(front == NULL) {
            return true;
        }
        return false;
    }
};

int main() {
    Queue *q = new Queue();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    q->push(1);
    q->push(2);
    q->push(3);
    cout<<"Is queue empty : "<<q->empty()<<endl;
    q->push(4);
    q->push(5);
    q->push(6);
    cout<<q->peek()<<" popped"<<endl;
    q->pop();
    cout<<q->peek()<<" popped"<<endl;
    q->pop();
    cout<<q->peek()<<" popped"<<endl;
    q->pop();
    cout<<q->peek()<<" popped"<<endl;
    q->pop();
    cout<<q->peek()<<" popped"<<endl;
    q->pop();
    cout<<"Front element : "<<q->peek()<<endl;
    cout<<"Is queue empty : "<<q->empty()<<endl;
    return 0;
}