//parameterised
#include<iostream>
using namespace std;
void sum1ton(int sum,int n){
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    sum1ton(sum+n,n-1);
}
int sum2(int n){
    if(n==0) return 0;
    else{
       return n+ sum2(n-1); 
    }
}
int main(){
    sum1ton(0,6);
    cout<<endl;
    sum2(5);
    return 0;
}