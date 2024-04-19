/*
   *
  ***
 *****
*******

*/

//logic written in notes
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of rows:";
    cin>>n;
    int nst=1;
    int nsp=n-1;  //is method me maths thodi km use ho ri hai as compared to previous

    for (int i = 1; i <=n; i++)
    { 
      //spaces
      for (int j = 1; j <=nsp; j++)
      {
        cout<<" ";
      }
      nsp--;

      //for stars
      for (int k = 1; k <=nst; k++)
      {
        cout<<"*";
      }
      nst+=2;
      cout<<endl;
      
      
    }
    
    return 0;
}