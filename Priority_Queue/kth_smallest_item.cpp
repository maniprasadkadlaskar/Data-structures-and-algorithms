#include<iostream>
#include<queue>
using namespace std;

int kthsmallest(int a[],int n,int key) {
    priority_queue <int> pq;
    for(int i=0;i < key;i++)
        pq.push(a[i]);
    for(int i =key;i < n;i++) {
        if(pq.top() > a[i]){
        pq.pop();
        pq.push(a[i]);
        }
    }
    return pq.top();
}

int main() {
    int a[5] = {1,5,9,2,4};
    int key = 4;
    int top = kthsmallest(a,5,key);
    cout<<key<<" smallest item is : "<<top<<endl;
    return 0;
}