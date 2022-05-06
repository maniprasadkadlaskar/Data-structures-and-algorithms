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

int maxRectangle(int b[][3],int r,int c) {
    int * arr = b[0];
    int maxrect = largestArea(arr,c);
    int maxele;
    for(int i=0;i < r;i++) {
        for(int j=0;j < c;j++) {
            if(b[i][j] == 1)
                arr[i] += 1;
            else
                arr[i] = 0;
        }
        maxele = largestArea(arr,c);
        maxrect = max(maxele,maxrect);
    }
    return maxrect;
}

int main() {
    int b[4][3] = 
        {
            {1,0,1},
            {0,1,1},
            {1,0,1},
            {1,1,0}
        };
    cout<<maxRectangle(b,4,3)<<endl;
    return 0;
}