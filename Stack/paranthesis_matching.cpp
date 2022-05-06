#include<iostream>
#include<stack>
using namespace std;

bool matchParanthesis(string s) {
    stack <char> c;
    int n = s.length();
    for(int i=0;i < n;i++) {
        char ch = s[i];
        if(ch == '(' || ch == '[' || ch == '{') {
            c.push(ch);
            continue;
        }
        if(c.empty()) {
            return 0;
        }

        switch(ch) {
            case ']' :
                if(c.top() == '[')
                    c.pop();
                break;
            case ')' :
                if(c.top() == '(')
                    c.pop();
                break;
            case '}' :
                if(c.top() == '{')
                    c.pop();
                break;
            default:
                return 0;
        }
    }
    return c.empty();
}

int main() {
    string s = "([])";
    if(matchParanthesis(s))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}