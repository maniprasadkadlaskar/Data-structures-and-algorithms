#include<iostream>
using namespace std;

int gcd(int a,int b) {
    if(b == 0)
        return a;
    gcd(b,a%b);
}

void rotate(int a[],int d,int n) {
    if(d == n || d == 0)
        return;
    d = d % n;
    int g = gcd(n,d);
    for(int i=0;i < g;i++) {
        int temp = a[i];
        int j = i;
        while (1) {
            int k = d + j;
            if(k >= n)
                k = k -n;
            if(k == 0)
                break;
            a[j] = a[k];
            j = k; 
        }
        a[j] = temp;
    }

}

void printarray(int a[],int n) {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int a[5] = {1,2,3,4,5};
    cout<<"Before rotation : ";
    printarray(a,5);
    rotate(a,2,5);
    cout<<"After rotation : ";
    printarray(a,5);
    return 0;
}