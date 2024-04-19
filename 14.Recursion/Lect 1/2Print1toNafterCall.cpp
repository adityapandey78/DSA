#include<iostream>
using namespace std;
void print(int n){
    if(n==0) return;//base case
    print(n-1);//pehle call ho rahi hai
    cout<<n<<endl;//fir kama ho raha hai
}
int main(){
    print(4);
    return 0;
}