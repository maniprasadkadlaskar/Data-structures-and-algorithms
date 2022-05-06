#include<iostream>
using namespace std;
#define n 5

class Queue {
    public:
    int *arr;
    int front,rear;

    Queue() {
        arr = new int[n];
        front = rear = -1;
    }

    void push(int val) {
        if(front == -1)
            front += 1;
    
        rear = (rear + 1) % n;
        arr[rear] = val;
    }

    void pop() {
        if(front == rear) {
            front = rear = -1;
            return;
        }
        front = (front + 1) % n;
    }

    int frontItem() {
        return arr[front];
    }

    int rearItem() {
        return arr[rear];
    }

    bool empty() {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }

    bool full() {
        if(front == (rear + 1)%n)
            return true;
        return false;
    }
};

int main() {
    Queue *q = new Queue();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    cout<<"Front item : "<<q->frontItem()<<endl;
    cout<<"Rear item : "<<q->rearItem()<<endl;
    cout<<"Is queue empty : "<<q->empty()<<endl;
    cout<<"Is queue full : "<<q->full()<<endl;
    cout<<q->frontItem()<<" popped"<<endl;
    q->pop();
    cout<<q->frontItem()<<" popped"<<endl;
    q->pop();
    cout<<q->frontItem()<<" popped"<<endl;
    q->pop();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    cout<<"Is queue full : "<<q->full()<<endl;
    q->push(6);
    q->push(7);
    q->push(8);
    cout<<"Is queue full : "<<q->full()<<endl;
    cout<<"Front item : "<<q->frontItem()<<endl;
    cout<<"Rear item : "<<q->rearItem()<<endl;
    cout<<"After removing all items......"<<endl;
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    return 0;
}