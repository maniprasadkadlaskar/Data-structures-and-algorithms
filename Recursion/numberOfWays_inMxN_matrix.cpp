#include<iostream>
using namespace std;

int numberOfWays(int m,int n) {
    if(m == 1 || n == 1)
        return 1;
    return numberOfWays(m-1,n) + numberOfWays(m,n-1);
}

int main() {
    int row = 4, col = 3;
    cout<<numberOfWays(row,col)<<endl;
    return 0;
}