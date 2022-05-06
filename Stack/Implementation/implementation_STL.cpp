#include<iostream>
#include<stack>
using namespace std;

int main()  {
    stack <int> s;
    s.push(12);
    s.push(3);
    s.push(5);
    s.push(8);
    cout<<"Is stack empty : "<<s.empty()<<endl;
    cout<<"Before pop"<<endl;
    cout<<"Top item is : "<<s.top()<<endl;
    s.pop();
    cout<<"After pop"<<endl;
    cout<<"Top item is : "<<s.top()<<endl;
    cout<<"Size of Stack : "<<s.size()<<endl;
    return 0;
}