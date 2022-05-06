#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int a[],int n,int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && a[l] > a[largest]) 
        largest = l;

    if(r < n && a[r] > a[largest])
        largest = r;
    
    if(largest != i) {
        swap(a[i] , a[largest]);
        heapify(a,n,largest);
    }
}

void deletion(int a[],int n) {
    a[0] = a[n-1];
    a[n-1] = 0;
    n = n-1;
    heapify(a,n,0);
}

void printheap(int a[],int n) {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int a[10] = {1,5,9,4,3};
    make_heap(&a[0],&a[4]);
    cout<<"Before deletion : ";
    printheap(a,5);
    deletion(a,5);
    cout<<"After deletion : ";
    printheap(a,4);
    return 0; 
}