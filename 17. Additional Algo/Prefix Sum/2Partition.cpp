//partition the array in such away that it divides the array into two contigous parts
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,5,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    //formation of prefix sum
    for (int i = 1; i < n; i++)
    {
        arr[i]+=arr[i-1];
    }

    //check if any x exists that divides it intot wo contagious parts
    bool flag=false;
    int idx=-1;
    for (int i = 1; i<n; i++)
    {
        if (2*arr[i]==arr[n-1])
        {
            flag=true;
            idx=i;
            break;
        }
        
    }
    if (flag) cout<<"Yes it can be partitioned at"<<" "<<idx;
    else
    {
        cout<<"It cannot be partitioned!";
    }
    
    
    
return 0;
}