//find maximum value of an array using recursion

#include<iostream>
#include<climits>
using namespace std;
void printMax(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    } if(max<arr[idx]) max=arr[idx];
    printMax(arr,n,idx+1,max);
}

// getiing the max in array

int maxInArray(int arr[],int n,int idx){
    if(idx==n) return INT_MIN;
    return max(arr[idx],maxInArray(arr,n,idx+1));
}
int main(){
    int arr[]={1,2,3,4,5,86,7,90,11,45};
    int n= sizeof(arr)/sizeof(arr[0]);
    //printMax(arr,n,0,INT_MIN);
    cout<<maxInArray(arr,n,0);

    
    return 0;
}