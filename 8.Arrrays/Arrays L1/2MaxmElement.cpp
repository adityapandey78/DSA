#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of the array:";
    cin>>n;
    int arr[n];
    //input
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    
    }
    int x;
    

    //search
    //check mark
    
    int index=-1,max=-1;
    for (int i = 0; i < n-1; i++)
    {
        if(max< arr[i]){
            max=arr[i];
            
        } 
    }
    cout<<"Element Found mamx is:"<<max;
    
}