/*Push zeroes to end while maintaining the relative order of other elements*/
#include<iostream>
using namespace std;
int main(){

   int arr[]={1,0,2,4,6,0,7,9,3,0,1,4};
   
   for (int i = 0; i <9; i++)
   {
    //traverse 
   
    for(int j=0;j<9-1-i;j++){
        if(arr[j]==0){
            swap(arr[j],arr[j+1]);
            
        }
    } 
    
    } 
   
   cout<<endl;
   for (int i = 0; i <9; i++)
   {
    cout<<arr[i]<<" ";
   }
    return 0;
}