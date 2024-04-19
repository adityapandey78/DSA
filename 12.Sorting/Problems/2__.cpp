/* Given an array with N distinct elements convert the given array to a form where all the elements are in trhe range from 0 to N-1 . The order of elements is the same , i.e., 0 is placed in the place of the smallest element, 1 is placed for the second smallest element,...N-1 is placed for the largest element  */

#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int main(){
    int arr[]={19,12,23,8,16};
    int n=5;

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    vector<int> v(n,0);//0 means not visited
    int x=0;

    for (int  i = 0; i < n; i++)
    {
        int min=INT16_MAX;
        int mindx=-1;
        for (int j = 0; j < n; j++)
        {
            if(v[j]==1) continue;
            else{
                if(min>arr[j]){
                    min=arr[j];
                    mindx=j;
                }
            }
        }
        arr[mindx]=x;
        v[mindx]=1; //visisted
        x++;

    }
    
    cout<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    


    return 0;
}