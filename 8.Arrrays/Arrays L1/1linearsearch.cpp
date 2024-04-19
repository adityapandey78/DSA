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
    cout<<"Enter the element you want to search:";
    cin>>x;

    //search
    //check mark
    bool flag=false;
    int index=-1;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]==x){
            flag=true;index=i;
        } 
    }
    if(flag==true) cout<<"Element Found at Index:"<<index;
    else cout<<"Element not found";
    return 0;
}