#include<iostream>
using namespace std;

void swap(int a[],int i,int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void display(int a[],int n) {
    cout<<"Sorted array is,"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
}

int main() {
    int n;
    cout<<"Enter size of array = ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements = ";
    for(int i =0;i<n;i++) 
        cin>>a[i];
    bool check = false;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]) {
                check = true;
                swap(a,j,j+1);   
            }
        if(!check)
            break;
    }
    display(a,n);
    return 0;
}