#include<iostream>
using namespace std;

void swap(int a[],int i,int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[],int l,int h){
    int i = l;
    int j = h;
    int pivot = a[l];
        while(i<j){
            while(a[i] <= pivot)
                i++;
            while(a[j] > pivot)
                j--;
            if(i<j)
                swap(a,i,j);
        }
    swap(a,l,j);
    return j;
}

void quickSort(int a[],int l,int h) {
    if(l<h) {
        int pivot = partition(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }
}

void display(int a[],int n) {
    cout<<"Sorted array is,"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
}

int main() {
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements = ";
    for(int i =0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n-1);
    display(a,n);
    return 0;
}