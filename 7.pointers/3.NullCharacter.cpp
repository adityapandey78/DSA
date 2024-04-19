#include<iostream>
using namespace std;
int main(){
    int *ptr1=NULL; //NULL= reserved address as 0X0
    int *ptr2=0; //null character -> 0
    int *ptr3 ='\0';
    cout<<ptr1<<" "<<ptr2<<" "<<ptr3; 
    return 0;
}