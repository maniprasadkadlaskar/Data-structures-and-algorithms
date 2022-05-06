#include<iostream>
using namespace std;

void towerOfHanoi(int n,char from,char to,char aux) {
    if(n == 1) {
        cout<<"MOve disk 1 from rod "<<from<<" to rod "<<to<<endl;
        return;
    }
    towerOfHanoi(n-1,from,aux,to);
    cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
    towerOfHanoi(n-1,aux,to,from);
}

int main() {
    towerOfHanoi(4,'A','C','B');
    return 0;
}