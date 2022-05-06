#include<iostream>
using namespace std;
#define n 5         // n IS SIZE OF QUEUE

class Queue {
    int *arr;
    int front;
    int rear;

    public :
    Queue() {
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    void push(int ele) {
        if(rear == n-1) {
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear] = ele;
    }

    void pop() {
        if(front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
    }

    int peek() {
        if(front > rear) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front]; 
    }

    bool empty() {
        if(front > rear) {
            return true;
        }
        return false;
    }

    bool full() {
        if(rear == n-1) {
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
    cout<<"Is queue full : "<<q->full()<<endl;
    q->push(4);
    q->push(5);
    q->push(6);
    cout<<"Is queue full : "<<q->full()<<endl;
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
    cout<<"Is queue empty : "<<q->empty()<<endl;
    return 0;
}