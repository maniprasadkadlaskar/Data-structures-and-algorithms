#include<iostream>
#include<unordered_set>
using namespace std;

int intersect(int a[],int n,int b[],int m) {
    unordered_set <int> set;
    int count = 0;
    for(int i =0;i < n;i++)
        set.insert(a[i]);
    for(int i=0;i < m;i++) {
        if(set.find(b[i]) != set.end()) {
            count ++;
            set.erase(b[i]);
        }
    }
    return count;
}

int main() {
    int a[5] = {5,10,15,5,10};
    int b[3] = {5,10,4};
    cout<<"Number of insect elements = "<<intersect(a,5,b,3)<<endl;
    return 0;
}