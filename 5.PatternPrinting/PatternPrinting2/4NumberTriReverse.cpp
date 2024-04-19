#include<iostream>
using namespace std;
int main(){
    int n ;
    cout<<"No. of Lines";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        for (int k = 1; k <=n-i; k++) //this loop for spaces
        {
            cout<<" ";
        }
        for (int  j =1; j <=i; j++)//lopp 2 for the right side
        { 
            cout<<j;

        }
        for (int  j = i-1; j >=1; j--)//lopp 3 for the right side
        {// the reason ki i-1 hai , isko 1 step neeche khiskana tha , coz patter sahi se print ni ho rha tha 
            cout<<j;

        }
        
        

        cout<<endl;
    }
    

    return 0;
}/*

 if we started from i=1 ij the 3rd loop, themn output 
    11
   1221
  123321
                                                                                                         12344321
    */