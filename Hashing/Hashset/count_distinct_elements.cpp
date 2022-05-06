#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countdistinct(vector <int> a) {
    unordered_set <int> set;
    for(int i : a) {
        set.insert(a[i]);
    }
    return set.size();
}

int main() {
    vector <int> a = {6,2,6,6,4,5};
    cout<<"Number of distinct elements = "<<countdistinct(a)<<endl;
    return 0;
}