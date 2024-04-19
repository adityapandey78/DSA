#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="123456";
    int x=stoi(str);

    //ye integer ko string me convert kr skta hai
    cout<<x+1;

    int a=1234567;
    string s= to_string(a);

    cout<<endl<<s;



}