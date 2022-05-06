#include<iostream>
using namespace std;

int binarySearch(int a[],int n,int key){
    int low = 0;
    int high = n-1;
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

int main() {
    int n;
    cout<<"Enter the size = ";
    cin>>n;
    int a[n];
    cout<<"Enter sorted array elements = ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int key;
    cout<<"Enter Key = ";
    cin>>key;
    int check = binarySearch(a,n,key);
    if(check != -1)
        cout<<"Present"<<endl;
    else
        cout<<"Not Present"<<endl;
    return 0;
}