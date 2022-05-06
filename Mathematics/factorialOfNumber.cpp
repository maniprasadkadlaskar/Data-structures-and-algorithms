#include<iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for(int i=1;i<=n;i++) 
        result *= i;
    return result;
}

int main() {
    int n;
    cout<<"Enter the number = ";
    cin>>n;
    cout<<"Factorial of entered number = "<<factorial(n)<<endl;
    return 0;
}