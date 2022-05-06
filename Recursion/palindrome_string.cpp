#include<iostream>
using namespace std;

bool palindrome(string s,int l,int r) {
    if(l >= r)
        return 1;
    if(s[l] != s[r])
        return 0;
    return palindrome(s,l+1,r-1);
}

int main() {
    string s = "refer";
    int n = s.length();
    if(palindrome(s,0,n-1))
        cout<<"Is Palindrome"<<endl;
    else
        cout<<"Is not Palindrome"<<endl;
    return 0;
}