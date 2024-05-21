#include<iostream>
using namespace std;
int hcf(int a ,int b){
    if(a==0) return b;
    else return hcf(b%a,a);//remainder / quotient
}
int main(){
    int a=23;
    int b=35;
    cout<<hcf(a,b);
    return 0;
}