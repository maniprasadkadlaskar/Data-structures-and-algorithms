#include<iostream>
using namespace std;

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
    for(int i=1;i<n;i++) {
        int temp = a[i];
        int j=i-1;
        while(j>=0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp; 
    }
    display(a,n);
    return 0;
}