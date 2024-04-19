#include<iostream>
using namespace std;
//normal method
// int pow( int x,int n){
//     if(n==0||n==1-) return 1;
//     return x*pow(x,n-1);
// }
int pow( int x,int n){
    int ans;
    if(n==1) return x;
    if(n%2==0)
    ans=pow(x,n/2);
    else  ans =pow(x,n/2)*x;
    return ans*ans;;
}

int main(){
    cout<<pow(2,9);
    return 0;
}