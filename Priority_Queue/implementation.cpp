#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue <int> pq;
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);
    cout<<"Size of priority_queue : "<<pq.size()<<endl;
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}