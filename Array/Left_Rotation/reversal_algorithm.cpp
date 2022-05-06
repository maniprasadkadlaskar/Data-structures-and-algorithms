#include<iostream>
using namespace std;

void reverse(int a[],int start,int end) {
    while(start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start ++; end --;
    }
}

void rotate(int a[],int d,int n) {
    if(d == n || d == 0)
        return;
    d = d % n;
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

void printarray(int a[],int n) {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int a[5] = {1,2,3,4,5};
    cout<<"Before rotation : ";
    printarray(a,5);
    rotate(a,2,5);
    cout<<"After rotation : ";
    printarray(a,5);
    return 0;
}