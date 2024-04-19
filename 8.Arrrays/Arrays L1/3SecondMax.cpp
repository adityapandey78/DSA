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
   
    

    
    
    
    int max=-1,smax=-1;
    for (int i = 0; i < n-1; i++)
    {
        if(max< arr[i]){
            max=arr[i];
            
        } 
        
        
    }
    for (int i = 0; i < n-1; i++)
    {
       if (arr[i]!=max && smax<arr[i] && smax!=max) //condtions me pehele hi likha hoga ki not equal to 
        {
            smax=arr[i];
        }
        
        
    }
    cout<<"Element Found max is:"<<max<<endl;
    cout<<"Element Found second smax is:"<<smax;
    
}