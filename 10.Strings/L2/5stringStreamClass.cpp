/*Given a semtemce , split every single word of the sentence in a new line */
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string str="Aditya Pandey is a hustler.";
    stringstream ss(str);
    string temp;
    while (ss>>temp)
    {
        cout<<temp<<endl;
    }
    
    return 0;
}