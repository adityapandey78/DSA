// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
//Brute force approach 
//worst tiem complexity
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={3,1,2,7,4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //Next greater element array 
    int nge[n];
    for (int i = 0; i < n; i++)
    {
        nge[i]=-1;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]>arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
        
    }
    cout<<"Mext Greater:"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<nge[i]<<" ";
    }
return 0;
}