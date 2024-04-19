#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="Aditya";
    cout<<str<<endl;
    str[1]='o';
    cout<<str<<endl;

    //in c++ strings are mutable which is not possible in Java
    return 0;
}