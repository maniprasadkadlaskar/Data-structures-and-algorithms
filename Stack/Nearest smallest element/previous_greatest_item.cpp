#include<iostream>
#include<deque>
using namespace std;

void nextSmallest(int a[],int n) {
    deque <int> d;
    for(int i =0;i < n;i++) {
        while(!d.empty() && d.back() <= a[i]) {
            d.pop_back();
        }
        if(d.empty())
            cout<<-1<<" ";
        else 
            cout<<d.back()<<" ";
        d.push_back(a[i]);
    }
}

int main() {
    int a[] = {20,12,25,20,15,5};
    nextSmallest(a,(sizeof(a)/sizeof(int)));
    return 0;
}