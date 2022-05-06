#include<iostream>
#include<queue>
using namespace std;

class Stack {
    public:
    queue <int> q1;
    
    void push(int val) {
        queue <int> q2;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }    
    }

    void pop() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack *s = new Stack();
    cout<<"Is stack empty : "<<s->empty()<<endl;
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    cout<<"Is stack empty : "<<s->empty()<<endl;
    cout<<s->top()<<" popped"<<endl;
    s->pop();
    cout<<s->top()<<" popped"<<endl;
    s->pop();
    cout<<"Remaining items are also popped......"<<endl;
    s->pop();
    s->pop();
    s->pop();
    cout<<"Is stack empty : "<<s->empty()<<endl;
    return 0;
}