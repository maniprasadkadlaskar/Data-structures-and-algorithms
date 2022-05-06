// To find largest sum subarray

#include<iostream>
using namespace std;

// int largestsum(int a[],int n) {
//     int totalmax = 0;
//     int max = 0;
//     for(int i =0;i<n;i++) {
//         max += a[i];
//         if(totalmax < max) 
//             totalmax = max;
//         if(max < 0) 
//             max = 0;
//     }
//     return totalmax;
// }

int largestsum(int a[],int n) {
    int totalmax = a[0];
    int max = a[0];
    for(int i=1;i<n;i++) {
        if(a[i] <= max + a[i])
            max += a[i];
        else
            max = a[i];
        if(max > totalmax)
            totalmax = max;
    }
    return totalmax;
}

int main() {
    int a[5] = {1,2,3,-1,-6};
    cout<<"Largest sum subarray is "<<largestsum(a,5)<<endl;
    return 0;
}