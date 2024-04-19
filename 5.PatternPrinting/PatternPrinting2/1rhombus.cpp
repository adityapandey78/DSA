/*
     *****
    *****
   *****
  *****
 *****     
 same as the q13 of part 1 i.e. star flipped triangle        
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
         for (int j = 1; j <=n-i; j++) 
        {
           cout<<" ";
        }
        for (int k = 1; k <= n; k++) //star flipped me k<=i rkhte the coz hme hr row me bs i stars chaiye the, but idhr rhombus me har row me same stars hi chaiye that's why n tk use kra
        {
           cout<<"*";
        }
        cout<<endl;

    }
    return 0;
}