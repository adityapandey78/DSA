/*
     *
    **
   ***
  ****
 *****               
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of rows:";
    cin>>n;
     for (int i = 1; i <= n; i++)
    {
        //for hashes or blanks
         for (int j = 1; j <=n-i; j++) //usually n+1-i hota hai but humme +1 htaya hai coz acc to pattern hme ek km chaiye neeche
        {
           cout<<"#";
        }
        for (int k = 1; k <= i; k++)
        {
           cout<<"*";
        }
        cout<<endl;

    }
    return 0;
}