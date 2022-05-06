#include<iostream>
#include<stack>
using namespace std;

int * previousSmaller(int a[],int n) {
    deque <int> s;
    int * ps = new int[n];
    for(int i=0;i < n;i++) {
        while(!s.empty() && a[s.back()] >= a[i]) {
            s.pop_back();
        }
        if(s.empty())
            ps[i] = -1;
        else
            ps[i] = s.back();
        s.push_back(i);
    }
    return ps;
}

int * nextSmaller(int a[],int n) {
    deque <int> s;
    int * ns = new int[n];
    for(int i=n-1;i >= 0;i--) {
        while(!s.empty() && a[s.back()] >= a[i]) {
            s.pop_back();
        }
        if(s.empty())
            ns[i] = n;
        else
            ns[i] = s.back();
        s.push_back(i);
    }
    return ns;
}

int largestArea(int a[],int n) {
    int * ps = previousSmaller(a,n);
    int * ns = nextSmaller(a,n);
    int max = -1;
    for(int i=0;i < n;i++) {
        int temp = (ns[i] - ps[i] -1) * a[i];
        if(temp > max)
            max = temp;
    }
    delete [] ps;
    delete [] ns;
    return max;
}

int main() {
    int a[] = {3,1,2,4};
    cout<<largestArea(a,(sizeof(a)/sizeof(int)))<<endl;
    return 0;
}