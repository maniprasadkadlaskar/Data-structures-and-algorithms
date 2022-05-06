#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    unordered_set <int> s;
    
    //To insert items in unordered set
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(10);

    //To print list items
    cout<<"Unordered set is , ";
    for(auto i = s.begin();i != s.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    //To check presence of item in list
    if(s.find(5) == s.end())
        cout<<"Not Found"<<endl;
    else
        cout<<"Found"<<endl;

    cout<<"Count of 10 is "<<s.count(10)<<endl;

    //To print number of items in unordered set
    cout<<"Size of unordered set is "<<s.size()<<endl;

    //To erase set items
    s.erase(6);
    s.erase(s.begin(),s.end());

    //To clear entire set
    s.clear();
    
    return 0;
}