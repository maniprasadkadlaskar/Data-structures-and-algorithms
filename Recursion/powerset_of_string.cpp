#include<iostream>
#include<vector>
using namespace std;

void powerSet(string s,int i,string curr) {
    if(i == s.length()) {
        cout<<curr<<endl;
        return;
    }

    powerSet(s,i+1,curr + s[i]);
    powerSet(s,i+1,curr);
}

int main() {
    string s = "abc";
    string curr;
    powerSet(s,0,curr);
    return 0;
}