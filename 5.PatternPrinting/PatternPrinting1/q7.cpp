/*
1
13
135
1357
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of rows:";
    cin>>n;
     for (int i = 1; i <= n; i++)
    {   
        int a=1;
        for (int j = 1; j <=i; j++)
        {
           cout<<2*j-1;  //printing the first j odd numbers in the row
        //    cout<<a;
        //    a+=2;  is tarah bhi kr skte hain
        }
        cout<<endl;

    }
    return 0;
}