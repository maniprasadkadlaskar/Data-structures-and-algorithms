#include<iostream>
using namespace std;

void merge(int a[],int l,int h,int mid){
        int i = l;
        int j = mid +1;
        int k = l;
        int b[h+1];
        while (i <= mid && j <= h)
        {
            if(a[i] > a[j]) {
                b[k] = a[j];
                j++;
            } else {
                b[k] = a[i];
                i++;
            }
            k++;
        }
        if(j > h) {
            while (i <= mid)
            {
                b[k] = a[i];
                i++; k++;
            }
        } else {
            while (j <= h)
            {
                b[k] = a[j];
                j++; k++;
            }
        }
        for(k = l;k <= h;k++)
            a[k] = b[k];
}

void mergeSort(int a[],int l,int h) {
    if(l<h) {
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid +1,h);
        merge(a,l,h,mid);
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
    mergeSort(a,0,n-1);
    display(a,n);
    return 0;
}