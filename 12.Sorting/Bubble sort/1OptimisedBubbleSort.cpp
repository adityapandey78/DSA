#include<iostream>
using namespace std;
int main(){

   int arr[]={1,2,4,6,7,9,3,1,4};
   
   for (int i = 0; i <9; i++)
   {
    //traverse 
    bool flag=true;
    for(int j=0;j<9-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag=false;
        }
    } 
    if(flag==true){
        break;
    } 
   }
   cout<<endl;
   for (int i = 0; i <9; i++)
   {
    cout<<arr[i]<<" ";
   }
   
   


    return 0;
}