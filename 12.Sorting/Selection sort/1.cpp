#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int main(){
    int arr[]={5,-4,1,4,2};
    int n=5;

    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;

    //selection sort
    for(int i=0;i<n;i++){
        int min = INT16_MAX;
        int mindx=-1;

        //minimum element calculation in orange box

        for (int  j = i; j < n; j++)
        {
           if(arr[j]<min){
            min=arr[j];
            mindx=j;
           }
        }
        swap(arr[i],arr[mindx]);
    }

    for(int ele: arr){
        cout<<ele<<" ";
    }
    return 0;
}