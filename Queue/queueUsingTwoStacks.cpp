#include<iostream>
#include<stack>
using namespace std;
class Queue {
    public:
    stack <int> s1;
    void push(int val) {
        s1.push(val);
    }

    void pop() {
        stack <int> s2;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        stack <int> s2;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }

    int rear() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
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
    q->push(6);  
    cout<<"Front item : "<<q->front()<<endl;
    cout<<"Rear item : "<<q->rear()<<endl;
    cout<<"Is queue empty : "<<q->empty()<<endl;
    cout<<q->front()<<" popped"<<endl;
    q->pop();
    cout<<q->front()<<" popped"<<endl;
    q->pop();
    cout<<"Every items are popped...."<<endl;
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    cout<<"Is queue empty : "<<q->empty()<<endl;
    return 0;
}