#include<iostream>
using namespace std;
void display(int a[]){
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
void change(int b[ ]){
    b[0]=100;
}
int main(){
    int arr[5]={1,2,3,4,5};
    //accessing the elements of array in another function
    //updating, pass by value/ pass by refrence
    display(arr);
    change(arr);
    display(arr);
    return 0;
}