#include<iostream>
#include<unordered_map>
using namespace std;

void findsubarray(int a[],int n,int sum) {
    unordered_map <int,int> map;
    int currsum = 0;
    for(int i=0;i<n;i++) {
        currsum += a[i];
        if(currsum == sum) {
            cout<<"Subarray of sum "<<sum<<"is from 0 to"<<i<<endl;
            return;
        }
        if(map.find(currsum - sum) != map.end()) {
            cout<<"Subarray of sum "<<sum<<"is from "<<map[currsum - sum] + 1<<" to "<<i<<endl;
            return;
        }
        map[currsum] = i;
    }
    cout<<"No subarray is found with sum "<<sum<<endl;
}

int main() {
    int a[5] = {1,2,3,4,5};
    int sum = 5;
    findsubarray(a,5,sum);
    return 0;
}