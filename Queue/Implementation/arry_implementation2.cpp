#include<iostream>
using namespace std;
#define n 4         // n IS SIZE OF QUEUE

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

    void enqueue(int ele) {
        if(rear == n-1) {
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear] = ele;
    }

    void dequeue() {
        if(front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=0;i < rear;i++) {
            arr[i] = arr[i+1];
        }
        rear--;
    }

    int getFront() {
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
    q->enqueue(1);
    q->enqueue(1);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);
    cout<<"Is queue full : "<<q->full()<<endl;
    q->dequeue();
    cout<<"Is queue full : "<<q->full()<<endl;
    q->dequeue();
    q->dequeue();
    q->enqueue(6);
    q->enqueue(7);
    q->enqueue(8);
    cout<<"Is queue full : "<<q->full()<<endl;
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    q->enqueue(8);
    cout<<"Is queue empty : "<<q->empty()<<endl;
    return 0;
}