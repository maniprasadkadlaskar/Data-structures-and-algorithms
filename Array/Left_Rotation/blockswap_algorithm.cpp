#include<iostream>
using namespace std;

void swap(int a[],int x,int y,int z) {
    int k = 0;
    while(k < z) {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
        x ++; y ++; k ++;
    }
}

void rotate(int a[],int d,int n) {
    int i,j;
    if(d == n || d == 0)
        return;
    i = d;
    j = n - d;
    while(i != j) {
        if(i < j) {
            swap(a,d-i,d+j-i,i);
            j -= i;
        }
        if(j < i) {
            swap(a,d-i,d,j);
            i -= j;
        }
    }
    swap(a,d-i,d,i);
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