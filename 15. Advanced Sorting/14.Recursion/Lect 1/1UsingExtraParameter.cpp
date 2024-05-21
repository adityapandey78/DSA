//print 1 to n using an extra parameter
#include<iostream>
using namespace std;

void print(int i,int n){
    if(i>n) return;
    cout<<i<<endl;
    print (i+1,n); //used extra parameter
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    print(1,n);
    return 0;
}