#include<iostream>
using namespace std;
int main(){
    int a=15;
    int *ptr=&a;
    int b= ++(*ptr);
    cout<<a<<" "<<b;
    return 0;
} //output would be 16 16 coz a pehle hi increment ho ja rha hai na
