#include<iostream>
#include<cstring>
using namespace std;

void display(bool a[],int n) {
    cout<<"The prime numbers are = ";
    for(int i =0;i <= n;i++)
        if(a[i])
            cout<<i<<"\t";
}

void sieveOfEratosthenes(int n) {
    bool a[n+1];
    memset(a,true,sizeof(a));
    a[0] = a[1] = false;
    for(int i =2;i*i <= n;i++) {
        for(int j = i*i;j <= n;j += i) 
            a[j] = false;
    }
    display(a,n);
}

int main() {
    int n;
    cout<<"Enter the range = ";
    cin>>n;
    sieveOfEratosthenes(n);
    return 0;
}