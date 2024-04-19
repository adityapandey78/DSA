#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your number \n";
    cin>>n;
    int a=1 , b=1;
    int sum=0;
    for (int i = 1; i <=n-2; i++)  //coz sum kr rhe hain to already hum 3rd term se chal rahe hain
    {
       sum=a+b;
       a=b;
       b=sum;
    }
    cout<<b;

    return 0;
}