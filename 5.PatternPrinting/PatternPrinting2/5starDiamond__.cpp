#include<iostream>
/*
  same as question 3
           *
          ***
         *****
        *******
         *****
          ***
           *
    print using the method of no. of spaces and no. of stars    

*/
using namespace std;
int main(){
     int n;
    cout<<"Enter the no. of rows:";
    cin>>n;
    int nst=1;
    int nsp=n-1;  

    for (int i = 1; i <=2*n-1; i++)
    { 
      //spaces
      for (int j = 1; j <=nsp; j++)
      {
        cout<<" ";
      }
      if(i<=n-1)  //n-1 kiya hai coz n-1 tak hi spaces print ho ri hain, also nth line me 0 spaces hain but wo agle line ke liye bhi decrease kr degi
      nsp--;
      else nsp++;

      //for stars
      for (int k = 1; k <=nst; k++)
      {
        cout<<"*";
      }
      if(i<=n-1)nst+=2;
      else nst-=2;
      cout<<endl;
      
      
    }
    return 0;
}