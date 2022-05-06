#include<iostream>
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

void buildHeap(int a[],int n) {
    int start = (n/2) - 1;

    for(int i = start;i >= 0;i--)
        heapify(a,n,i);
}

void printheap(int a[],int n) {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int a[5] = {1,5,6,9,2};
    buildHeap(a,5);
    printheap(a,5);
    return 0;
}