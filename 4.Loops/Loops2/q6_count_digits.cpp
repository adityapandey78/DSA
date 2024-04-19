/*WAP to count digits of a given number*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number \n";
    cin>>n;
    int count=0;
    int a=n;        //isse a ki value fix kri 0 ke liye coz n to change ho rha hai na baaar baar na
    while (n>0)
    {
        n/=10;
        count++;
    }
    if(a==0) cout<<1;
    else cout<<count<<endl;

    return 0;
}