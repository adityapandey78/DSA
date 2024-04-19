#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){

   string s;
    //cin>>s;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s;/*
    INPUT: Aditya Pandey Stay Calm Buddy!
    OUTPUT:
        !ABCPSaaaaddddeilmnttuyyyy
    */

   //pehle spaces print hui and then capital coz idhr ASCII value ke hisaab se sort hota hai, since Captial letters ki ASCII value ki chhoti hoti hai
   
    return 0;
}