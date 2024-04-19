#include<iostream>
using namespace std;
void change(int a[]){
    a[0]=100;
}
void change2D(int a[][3]){ //arrays jb pass kr rhe hote hain to rows and coloumns dono dene pdte hain
    a[0][0]=100;
}
int main(){
    // int a[3]={1,2,3};
    // cout<<a[0]<<endl;
    // change(a);
    // cout<<a[0]<<endl;
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};

    //rows rahe na rahe coloumn rehna chahiye
    change2D(arr);
    cout<<arr[0][0];


    return 0;
}