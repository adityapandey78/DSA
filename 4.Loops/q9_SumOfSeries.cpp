/*Print the sum of the series 1+2-3+4-5+6-7+8...*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number \n";
    cin>>n;
    int sum=0;
    // for (int  i = 1; i <=n; i++)
    // {
    //     if(i%2!=0)sum+=i; //odd ko sum karo
    //     else sum-=i;    //even ko minus karo
    // }
    // cout<<sum;
    // METHOD 2
    if(n%2==0) sum=-n/2;
    else sum= -n/2 +n;
    cout<<sum;
     
    return 0;
}