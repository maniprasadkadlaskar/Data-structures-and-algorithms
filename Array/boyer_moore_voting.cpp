#include<iostream>
using namespace std;

int findmajority(int a[],int n) {
    int votes = 1;
    int index = 0;
    for(int i =1;i<n;i++) {
        if(a[i] == a[index])
            votes ++;
        else
            votes --;
        if(votes == 0) {
            index = i;
            votes = 1;
        }
    }
    int count = 0;
    for(int i =0;i<n;i++) {
        if(a[i] == a[index])
            count ++;
    }
    if(count > n/2)
        return index;
    else
        return -1;
}

int main() {
    int a[8] = {2,2,2,1,5,2,7,2};
    int m = findmajority(a,8);
    if(m != -1)
        cout<<"Majority element is "<<a[m]<<endl;
    else
        cout<<"No majority element"<<endl; 
    return 0;
}