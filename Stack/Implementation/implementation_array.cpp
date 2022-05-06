#include<iostream>
using namespace std;

class Stack {
    public :
        int * a;
        int capacity;
        int top;
        Stack (int capacity) {
            this->capacity = capacity;
            top = -1;
            a = new int(capacity);
        }

        void push(int data) {
            if(top == capacity-1) {
                cout<<"Stack Overflow!!"<<endl;
                return ;
            }
            top ++;
            a[top] = data;
        }

        int pop() {
            int result = a[top];
            top --;
            return result;
        }

        int peek() {
            return a[top];
        }

        bool isempty() {
            return top == -1;
        }

        int size() {
            return top + 1;
        }
};

int main() {
    Stack * s = new Stack(5);
    cout<<"Is stack empty : "<<s->isempty()<<endl;
    s->push(2);
    s->push(1);
    s->push(4);
    s->push(7);
    cout<<"Top item is : "<<s->peek()<<endl;
    cout<<"Size of stack : "<<s->size()<<endl;
    cout<<"Popped item is : "<<s->pop()<<endl;
    return 0;
}