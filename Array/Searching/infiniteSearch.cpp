#include<iostream>
using namespace std;

int binarySearch(int a[],int low,int high,int key) {
    int mid = (low+high)/2;
    while(low<=high){
    if(a[mid] == key)
        return mid;
    if(key > a[mid]) {
        low = mid +1;
    } else {
        high = mid -1;
    }
    mid = (low+high)/2;
    }
    return -1;
}

void infiniteSearch(int a[],int n,int key) {
    int l = 0;
    int h = n-1;
    while(a[h] < key) {
        l = h;
        h = 2*h;
    }
    int check = binarySearch(a,l,h,key);
    if(check != -1)
        cout<<"Present"<<endl;
    else
        cout<<"Not Present"<<endl;
}

int main() {
    int n;
    cout<<"Enter size of array = ";
    cin>>n;
    int a[n];
    cout<<"Enter sorted array elements = ";
    for(int i =0;i<n;i++) 
        cin>>a[i];
    int key;
    cout<<"Enter key = ";
    cin>>key;
    infiniteSearch(a,n,key);
    return 0;
}