/*WAP to print the sum of digits of a given number*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number \n";
    cin>>n;
    int sum=0,last=0;
    int a=n;        
    while (n>0)
    {
        last=n%10;
        sum+=last;
        n/=10;
    }
    if(a==0) cout<<0;
    else cout<<sum<<endl;

    return 0;
}