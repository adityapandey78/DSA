#include<iostream>
using namespace std;

void pip(int n){
    if(n==0) return;
    
    cout<<"Pre"<<n<<endl;
    pip(n-1);
    cout<<"IN"<<n<<endl;
    pip(n-1);
    cout<<"Post"<<n<<endl;
}
int main(){
    pip(3);
    cout<<endl;
    return 0;
}