#include<iostream>
#include<stack>
using namespace std;

void nextSmallest(int a[],int n) {
    stack <int> s;
    int *arr = new int[n];
    for(int i =n-1;i >= 0;i--) {
        while(!s.empty() && s.top() >= a[i]) {
            s.pop();
        }
        if(s.empty())
            arr[i] = -1;
        else 
            arr[i] = s.top();
        s.push(a[i]);
    }

    for(int i=0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int a[] = {20,12,25,20,15,5};
    nextSmallest(a,(sizeof(a)/sizeof(int)));
    return 0;
}