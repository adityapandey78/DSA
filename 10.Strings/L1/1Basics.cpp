#include<iostream>
#include<string>
using namespace std;
int main(){
    // string str="Aditya Pandey";
    // cout<<str;

    string s;  
    // cin>>s;  //will take the string till the space

    // cout<<s;
    getline(cin,s);
    cout<<s;
    
    return 0;
}