#include<iostream>
using namespace std;
void hanoi(int n,char a,char b,char c){
if(n==0)return;
hanoi(n-1,a,c,b);//a se b me shift krna hai  c ki help leke //first stage
cout<<a<<"->"<<c<<endl;
hanoi(n-1,b,a,c); //  b se c shift krna hai a ki help leke //second stage
}
int main(){
    int n=3;

    hanoi(n,'A','B','C');
    return 0;
}