#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(6);  
    v.push_back(1);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(1);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(9); 
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    return 0;
}