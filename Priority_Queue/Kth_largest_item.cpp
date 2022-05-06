#include<iostream>
using namespace std;
class MinHeap {
    public :
        int size;
        int *arr;
        MinHeap(int key,int *a);
        void buildHeap();
        void heapify(int);
};

MinHeap :: MinHeap(int key,int *a) {
    size = key;
    arr = a;
    buildHeap();
}

void MinHeap :: heapify(int i) {
    if(i >= size/2)
        return;
    
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < size && arr[l] < arr[smallest]) 
        smallest = l;

    if(r < size && arr[r] < arr[smallest])
        smallest = r;
    
    if(smallest != i) {
        swap(arr[i] , arr[smallest]);
        heapify(smallest);
    }
}

void MinHeap :: buildHeap() {
    for(int i = (size/2 -1);i >= 0;i--){
        heapify(i);
    }
}

void kthLargest(int a[],int n,int key) {
    MinHeap *m = new MinHeap(key,a);
    for(int i =key;i < n;i++) {
        if(a[0] > a[i])
            continue;
        else {
            a[0] = a[i];
            m->heapify(0);
        }
    }
}

int main() {
    int a[5] = {1,5,9,2,4};
    int key = 2;
    kthLargest(a,5,key);
    cout<<key<<" largest item is : "<<a[0]<<endl;
    return 0;
}