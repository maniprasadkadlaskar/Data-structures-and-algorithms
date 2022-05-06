#include<iostream>
#include<deque>
using namespace std;

void nextSmallest(int a[],int n) {
    deque <int> d;
    int * arr = new int[n];
    for(int i =n-1;i >= 0;i--) {
        while(!d.empty() && d.back() <= a[i]) {
            d.pop_back();
        }
        if(d.empty())
            arr[i] = -1;
        else 
            arr[i] = d.back();
        d.push_back(a[i]);
    }
    for(int i=0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int a[] = {5,15,20,25,12,20};
    nextSmallest(a,(sizeof(a)/sizeof(int)));
    return 0;
}