#include<iostream>
#include<algorithm>
using namespace std;

void insertion(int a[],int n,int num) {
    a[n] = num;
    int i = n;
    while(i > 0) {
        int parent = i/2;
        if(a[i] > a[parent]) {
            swap(a[i],a[parent]);
            i = parent;
        } else
            return;
    }
}

void printheap(int a[],int n) {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int a[10] = {1,5,9,4,3};
    make_heap(&a[0],&a[4]);
    int num;
    cout<<"Enter number to inserted : ";
    cin>>num;
    insertion(a,5,num);
    printheap(a,6);
    return 0; 
}