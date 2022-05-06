#include<iostream>
using namespace std;

void swap(int a[],int i,int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selectionSort(int a[],int n) {
    int i = 0;
    for(i = 0;i<n-1;i++) {
        int min = i;
        for(int j =i;j<n;j++) {
            if(a[min] > a[j])
                min = j;
        }
        if(min != i)
            swap(a,min,i);
    }
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
    selectionSort(a,n);
    display(a,n);
    return 0;
}