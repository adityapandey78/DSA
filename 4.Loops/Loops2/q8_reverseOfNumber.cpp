/*WAP to print the reverse of a given number*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number \n";
    cin>>n;
    int reverse=0,last=0; //last=last digit
    int a=n;        
    while (n>0)
    {
        last=n%10;
        reverse*=10;
        reverse+=last;
        n/=10;
    }
    if(a==0) cout<<0;
    else cout<<reverse<<endl;

    return 0;
}