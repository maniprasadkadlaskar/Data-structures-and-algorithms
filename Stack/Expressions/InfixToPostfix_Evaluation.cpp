#include<iostream>
#include<stack>
using namespace std;

int  prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
            return 2;
    else if(c == '+' || c == '-')
            return 1;
    else
        return -1;
}

// char operation(char a,char b,char t) {
//     int r;
//     if(t == '+')
//         r = (int) a + (int) b;
//     if(t == '-')
//         r = (int) a - (int) b;
//     if(t == '*')
//         r = (int) a * (int) b;
//     if(t == '/')
//         r = (int) a / (int) b;
//     if(t == '^')
//         r = (int) a ^ (int) b;

//     return (char) r;
// }

// void evaluation(string s) {
//     stack <char> c;
//     int n = s.length();
//     for(int i=0;i < n;i++) {
//         char t = s[i];
//         if(t == '+' || t == '-' || t == '*' || t == '/' || t == '^') {
//             char second_op = c.top();
//             c.pop();
//             char first_op = c.top();
//             c.pop();
//             char result = operation(first_op,second_op,t);
//             c.push(result);
//         }
//         else
//         c.push(t);
//     }
//     char ans = c.top();
//     c.pop();
//     cout<<ans<<endl;
// }

void conversion(string s) {
    stack <char> c;
    int n = s.length();
    string postFix;

    for(int i=0;i < n;i++) {
        char t = s[i];
        if(t >= 'a' && t <= 'z' || t >= '0' && t <= '9') {
            postFix += t;
        } else 
        if(t == '(')
            c.push(t);
        else
        if(t == ')') {
            while(c.top() != '(') {
                postFix += c.top();
                c.pop();
            }
            c.pop();
        } else
        {
            while(!c.empty() && prec(t) <= prec(c.top())) {
                postFix += c.top();
                c.pop();
            }
            c.push(t);
        }
    }

    while(!c.empty()) {
        postFix += c.top();
        c.pop();
    }
    cout<<postFix<<endl;
    // evaluation(postFix);
}

int main() {
    string s = "10*2/(3+4)*5";
    conversion(s);
    return 0;
}