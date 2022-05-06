#include<iostream>
using namespace std;

int trailingzeroes(int n) {
    int result = 0;
    int i=5;
    while(i<=n){
        result += n/i;
        i = i*5;
    }
    return result; 
}

int main() {
    int n;
    cout<<"Enter the number = ";
    cin>>n;
    cout<<"Trailing zeroes in factorial of entered number = "<<trailingzeroes(n)<<endl;
    return 0;
}