#include<iostream>
#include<stack>
using namespace std;

void previousSmallest(int a[],int n) {
    stack <int> s;
    for(int i=0;i < n;i++) {
        while(!s.empty() && s.top() >= a[i]) {
            s.pop();
        }
        if(s.empty())
            cout<<-1<<" ";
        else 
            cout<<s.top()<<" ";
        s.push(a[i]);
    }
    cout<<endl;
}

int main() {
    int a[] = {5,15,20,25,12,20};
    previousSmallest(a,(sizeof(a)/sizeof(int)));
    return 0;
}