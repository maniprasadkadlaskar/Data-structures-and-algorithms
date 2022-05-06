#include<iostream>
#include<unordered_set>
using namespace std;

int arrayunion(int a[],int n,int b[],int m) {
    unordered_set <int> set;
    for(int i=0;i<n;i++)
        set.insert(a[i]);
    for(int i=0;i<m;i++)
        set.insert(b[i]);
    return set.size();
}

int main() {
    int a[5] = {7,7,5,6,3};
    int b[4] = {1,2,3,4};
    cout<<"Size of union of array is "<<arrayunion(a,5,b,4)<<endl;
    return 0;
}